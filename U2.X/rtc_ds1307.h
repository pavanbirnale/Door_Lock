#ifndef RTC_DS1307_H
#define RTC_DS1307_H

void rtc_set_time(unsigned char h, unsigned char m, unsigned char s);
void rtc_get_time(unsigned char *h, unsigned char *m, unsigned char *s);

#endif