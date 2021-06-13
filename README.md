# HC32Fx-GCC
HC32Fx gcc template project.


### step1. Download GCC
Download [GNU Arm Embedded Toolchain](https://launchpad.net/gcc-arm-embedded/+download) with your system, extract to */Developer/gcc-arm-none-eabi*.


### step2. Extract CMSIS
The Common Microcontroller Software Interface Standard (CMSIS) is a vendor-independent abstraction layer for microcontrollers that are based on Arm Cortex processors. 

Download [HDSC pack](https://developer.arm.com/embedded/cmsis/cmsis-packs/devices), unzip to take [offcial pack files](https://github.com/hdscmcu/pack).

```bash
unzip HDSC.HC32F005.1.0.1.pack
cp Device/Include/HC32F005.h <project>/bsp/inc/hc32f005x6.h
dos2unix <project>/bsp/inc/hc32f005x6.h
# vim bsp/inc/hc32fx.h to add HC32Fx device macro support
```

### step3. Build VectorTable
`python generate_vt.py <MCU> <Core> `


### step4. Make


### Reference
* ["Bare Metal" STM32 Programming](https://vivonomicon.com/2018/04/02/bare-metal-stm32-programming-part-1-hello-arm/)
* [STM32_quickstart](https://github.com/WRansohoff/STM32_quickstart)
