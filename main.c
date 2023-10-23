#include <stdio.h>
#include <stdint.h>

//--------------------------------------------------
// This template util for get CPUID processor info
//--------------------------------------------------
// Information from:
//  * https://en.wikipedia.org/wiki/CPUID
//--------------------------------------------------

struct cpuinfo
{
    union
    {
        struct
        {
            /*TODO:implement maybe*/
        }bits;
        uint32_t raw;
    }eax;

    union
    {
        struct
        {
            /*TODO:implement maybe*/
        }bits;
        uint32_t raw;
    }ebx;

    union
    {
        struct
        {
            uint8_t sse3      :1;
            uint8_t pclmulqdq :1;
            uint8_t dtest64   :1;
            uint8_t monitor   :1;
            uint8_t ds_cpl    :1;
            uint8_t vmx       :1;
            uint8_t smx       :1;
            uint8_t est       :1;
            uint8_t tm2       :1;
            uint8_t ssse3     :1;
            uint8_t cnxt_id   :1;
            uint8_t sdbg      :1;
            uint8_t fma       :1;
            uint8_t cx16      :1;
            uint8_t xtpr      :1;
            uint8_t pdcm      :1;
            uint8_t _reserved_not_used_1:1;
            uint8_t pcid      :1;
            uint8_t dca       :1;
            uint8_t sse41     :1;
            uint8_t sse42     :1;
            uint8_t x2apic    :1;
            uint8_t movbe     :1;
            uint8_t popcnt    :1;
            uint8_t tsc_readline:1;
            uint8_t aes       :1;
            uint8_t xsave     :1;
            uint8_t osxsave   :1;
            uint8_t avx       :1;
            uint8_t fx6c      :1;
            uint8_t rdnrd     :1;
            uint8_t hypervisor:1;
        }bits;
        int32_t raw;
    }ecx;

    union
    {
        struct
        {
            uint8_t fpu  :1;
            uint8_t vme  :1;
            uint8_t de   :1;
            uint8_t pse  :1;
            uint8_t tsc  :1;
            uint8_t msr  :1;
            uint8_t pae  :1;
            uint8_t mce  :1;
            uint8_t cx8  :1;
            uint8_t apic :1;
            uint8_t _reserved_not_used_1:1;
            uint8_t sep  :1;
            uint8_t mtrr :1;
            uint8_t pge  :1;
            uint8_t mca  :1;
            uint8_t cmov :1;
            uint8_t pat  :1;
            uint8_t pse36:1;
            uint8_t psn  :1;
            uint8_t clfsh:1;
            uint8_t _reserved_not_used_2:1;
            uint8_t ds   :1;
            uint8_t acpi :1;
            uint8_t mmx  :1;
            uint8_t fxsr :1;
            uint8_t sse  :1;
            uint8_t sse2 :1;
            uint8_t ss   :1;
            uint8_t htt  :1;
            uint8_t tm   :1;
            uint8_t ia64 :1;
            uint8_t pbe  :1;
        }bits;
        int32_t raw;
    }edx;

};

void cpuinfo_print(struct cpuinfo info)
{
    printf(
            "-----\n"
            ":ECX:\n"
            "-----\n"
            ": %d : sse3     \n"
            ": %d : pclmulqdq\n"
            ": %d : dtest64  \n"
            ": %d : monitor  \n"
            ": %d : ds_cpl   \n"
            ": %d : vmx      \n"
            ": %d : smx      \n"
            ": %d : est      \n"
            ": %d : tm2      \n"
            ": %d : ssse3    \n"
            ": %d : cnxt_id  \n"
            ": %d : sdbg     \n"
            ": %d : fma      \n"
            ": %d : cx16     \n"
            ": %d : xtpr     \n"
            ": %d : pdcm     \n"
            ": %d : pcid     \n"
            ": %d : dca      \n"
            ": %d : sse41    \n"
            ": %d : sse42    \n"
            ": %d : x2apic   \n"
            ": %d : movbe    \n"
            ": %d : popcnt   \n"
            ": %d : tsc_readline\n"
            ": %d : aes      \n"
            ": %d : xsave    \n"
            ": %d : osxsave  \n"
            ": %d : avx      \n"
            ": %d : fx6c     \n"
            ": %d : rdnrd    \n"
            ": %d : hypervisor\n"
            "-----\n"
            ":EDX:\n"
            "-----\n"
            ": %d : fpu  \n"
            ": %d : vme  \n"
            ": %d : de   \n"
            ": %d : pse  \n"
            ": %d : tsc  \n"
            ": %d : msr  \n"
            ": %d : pae  \n"
            ": %d : mce  \n"
            ": %d : cx8  \n"
            ": %d : apic \n"
            ": %d : sep  \n"
            ": %d : mtrr \n"
            ": %d : pge  \n"
            ": %d : mca  \n"
            ": %d : cmov \n"
            ": %d : pat  \n"
            ": %d : pse36\n"
            ": %d : psn  \n"
            ": %d : clfsh\n"
            ": %d : ds   \n"
            ": %d : acpi \n"
            ": %d : mmx  \n"
            ": %d : fxsr \n"
            ": %d : sse  \n"
            ": %d : sse2 \n"
            ": %d : ss   \n"
            ": %d : htt  \n"
            ": %d : tm   \n"
            ": %d : ia64 \n"
            ": %d : pbe  \n",
            ////////////////
            info.ecx.bits.sse3,
            info.ecx.bits.pclmulqdq,
            info.ecx.bits.dtest64,
            info.ecx.bits.monitor,
            info.ecx.bits.ds_cpl,
            info.ecx.bits.vmx,
            info.ecx.bits.smx,
            info.ecx.bits.est,
            info.ecx.bits.tm2,
            info.ecx.bits.ssse3,
            info.ecx.bits.cnxt_id,
            info.ecx.bits.sdbg,
            info.ecx.bits.fma,
            info.ecx.bits.cx16,
            info.ecx.bits.xtpr,
            info.ecx.bits.pdcm,
            info.ecx.bits.pcid,
            info.ecx.bits.dca,
            info.ecx.bits.sse41,
            info.ecx.bits.sse42,
            info.ecx.bits.x2apic,
            info.ecx.bits.movbe,
            info.ecx.bits.popcnt,
            info.ecx.bits.tsc_readline,
            info.ecx.bits.aes,
            info.ecx.bits.xsave,
            info.ecx.bits.osxsave,
            info.ecx.bits.avx,
            info.ecx.bits.fx6c,
            info.ecx.bits.rdnrd,
            info.ecx.bits.hypervisor,
            info.edx.bits.fpu,
            info.edx.bits.vme,
            info.edx.bits.de,
            info.edx.bits.pse,
            info.edx.bits.tsc,
            info.edx.bits.msr,
            info.edx.bits.pae,
            info.edx.bits.mce,
            info.edx.bits.cx8,
            info.edx.bits.apic,
            info.edx.bits.sep,
            info.edx.bits.mtrr,
            info.edx.bits.pge,
            info.edx.bits.mca,
            info.edx.bits.cmov,
            info.edx.bits.pat,
            info.edx.bits.pse36,
            info.edx.bits.psn,
            info.edx.bits.clfsh,
            info.edx.bits.ds,
            info.edx.bits.acpi,
            info.edx.bits.mmx,
            info.edx.bits.fxsr,
            info.edx.bits.sse,
            info.edx.bits.sse2,
            info.edx.bits.ss,
            info.edx.bits.htt,
            info.edx.bits.tm,
            info.edx.bits.ia64,
            info.edx.bits.pbe);
}

struct cpuinfo cpuinfo_get()
{
    int32_t  EAX=0; /*model + family*/
    int32_t  EBX=0; /*features      */
    int32_t  ECX=0; /*features flags*/
    int32_t  EDX=0; /*features flags*/
    //----------------------------------
    // CPUID have multiple eax settings
    // for different info modes this
    // used only mode 0x1 for basic info
    //----------------------------------
    asm("mov $0x1 , %eax;");/*set mode*/
    asm("cpuid;");/*call instuction*/
    /*   read informations bits     */
    asm("mov %%eax, %0;":"=r" (EAX));
    asm("mov %%ebx, %0;":"=r" (EBX));
    asm("mov %%ecx, %0;":"=r" (ECX));
    asm("mov %%edx, %0;":"=r" (EDX));

    struct cpuinfo info =
    {
        .eax.raw = EAX,
        .ebx.raw = EBX,
        .ecx.raw = ECX,
        .edx.raw = EDX,
    };
    return info;
}

int main(int argc, char *argv[])
{
    struct cpuinfo info = cpuinfo_get();
    cpuinfo_print(info);
    return 0;
}

