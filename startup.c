extern unsigned char _data_start,
    _data_end,
    _bss_start,
    _bss_end,
    _data_lma,
    _bss_lma;
extern int main();

void reset_handler()
{
    // .bss & .data sections copy
    unsigned char *itr          = &_data_start;
    unsigned char *p_data_end   = &_data_end;
    unsigned char *p_bss_end    = &_bss_end;
    unsigned char *p_data_lma   = &_data_lma;
    unsigned char *p_bss_lma    = &_bss_lma;
    for (; itr != p_data_end; itr++)
        *itr = *p_data_lma++;

    itr = &_bss_start;
    for (; itr != p_bss_end; itr++)
    {
        *itr = *p_bss_lma++;
        *itr = 0;
    }

    main();
}
