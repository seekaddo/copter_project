/*
 *  ======== StartBIOS.c ========
 *
 */

/* XDCtools Header files */
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

/* Board Header files */
#include <Board.h>

/* Application headers */
#include <RN4678.h>
#include <TI_Joystick.h>

/*
 * NOTE: All local variables in main() will be discarded once BIOS_start() is called.
 */

int main(void)
{
    uint32_t ui32SysClock;

    /* Call board init functions. */
    ui32SysClock = Board_initGeneral(120*1000*1000);
    (void)ui32SysClock; // We don't really need this (yet)

    Board_initGPIO();

    // initialize the RN4678 and start the communication task
    init_bt();
    System_printf("Created RN4678 Task\n");
    System_flush();


    EdM_ADC_Init();
    System_printf("Setting up ADC for Joystick Done!! \n");
    System_flush();

    System_printf("Setting up EduMiki Joystick Task !! \n");
    System_flush();
    setUpJoyStick_Task();


    /* SysMin will only print to the console upon calling flush or exit */
    System_printf("Start BIOS\n");
    System_flush();

    /* Start BIOS */
    BIOS_start();
}
