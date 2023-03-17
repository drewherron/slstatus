/* See LICENSE file for copyright and license details. */
#include <time.h>

const char *
kanji(const char *unused) {
	char *kanji[]={"月","火","水","木","金","土","日"};
	int map[]={0,3,2,5,0,3,5,1,4,6,2,4};
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);
	int m=tm.tm_mon+1,y=tm.tm_year+1900-(m<3);
	int wd=(y+y/4-y/100+y/400+map[m-1]+tm.tm_mday)%7;
	return kanji[wd-1];
}
