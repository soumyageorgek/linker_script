extern unsigned char _etext, _sdata, _edata, _sbss, _ebss, __stack;

__attribute__((naked))
void __stop_progExec__(void)
{
	while(1);
}

__attribute__((naked)) 
void dummy_function(void)
{
    while(1); 
}
  
__attribute__((naked)) 
void startup(void)
{
	asm("mov.w #__stack - 4, r1\n");
	asm("mov r1, r4\n");
    
	unsigned char *src, *dst;

    src = &_etext;
    dst = &_sdata;

    while(dst < &_edata)
    	*(dst++) = *(src++);
    
	src = &_sbss;

	while(src < &_ebss)
		*(src++) = 0;

    main();
}

__attribute__((section(".vectors")))
void (*InterruptVectors[])(void) = {
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
    dummy_function,
	startup
}; 
