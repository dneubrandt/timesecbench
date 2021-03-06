#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#define ARMV8_PMCR_MASK         0x3f
#define ARMV8_PMCR_E            (1 << 0) /*  Enable all counters */
#define ARMV8_PMCR_P            (1 << 1) /*  Reset all counters */
#define ARMV8_PMCR_C            (1 << 2) /*  Cycle counter reset */
#define ARMV8_PMCR_D            (1 << 3) /*  Enable divider by 64 */
#define ARMV8_PMCR_N_MASK       0x1f

#define ARMV8_PMUSERENR_EN_EL0  (1 << 0) /*  EL0 access enable */
#define ARMV8_PMUSERENR_CR      (1 << 2) /*  Cycle counter read enable */
#define ARMV8_PMUSERENR_ER      (1 << 3) /*  Event counter read enable */

#define ARMV8_PMCNTENSET_EL0_ENABLE (1<<31) /* *< Enable Perf count reg */

#define PERF_DEF_OPTS (1 | 16)

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Pierre Jamelot");
MODULE_DESCRIPTION("Enable performance counters for users.");
MODULE_VERSION("0.01");

static void disable_prefetch(void)
{
    unsigned long value = 0;
    printk("Manipulating data prefething register\n");
    asm volatile("mrs %0, S3_1_C15_C2_0" : "=r" (value)); // read register
    printk("Reading old S3_1_C15_C2_0 = %lx)\n", value);
    asm volatile("msr S3_1_C15_C2_0, %0" :: "r" (value)); // write register

    printk("Done manipulating data prefetching register\n");
}

static int __init pc_enable_init(void) {
    /*Enable user-mode access to counters. */
    asm volatile("msr pmuserenr_el0, %0" : : "r"((u64)ARMV8_PMUSERENR_EN_EL0|ARMV8_PMUSERENR_ER|ARMV8_PMUSERENR_CR));

    /*   Performance Monitors Count Enable Set register bit 30:0 disable, 31 enable. Can also enable other event counters here. */ 
    asm volatile("msr pmcntenset_el0, %0" : : "r" (ARMV8_PMCNTENSET_EL0_ENABLE));

    /* Enable counters */
    unsigned long val=0;
    asm volatile("mrs %0, pmcr_el0" : "=r" (val));
    asm volatile("msr pmcr_el0, %0" : : "r" (val|ARMV8_PMCR_E & (~ARMV8_PMCR_D)));
    printk(KERN_INFO "Enable performance counters for users.\n");
    return 0;
}

static void __exit pc_enable_exit(void) {
    printk(KERN_INFO "Leaving PC enable\n");
}

module_init(pc_enable_init);
module_exit(pc_enable_exit);