//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_jtag.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//




void error(void)
{
    asm("     ESTOP0"); // Test failed!! Stop!
    for (;;);
}
