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

/*
Sunday		日曜日	nichiyoubi
Monday		月曜日	getsuyoubi
Tuesday		火曜日	kayoubi
Wednesday	水曜日	suiyoubi
Thursday	木曜日	mokuyoubi
Friday		金曜日	kin'youbi
Saturday	土曜日	doyoubi

nichi 		日 			Day
hi (taiyou) 日（太陽）	Sun

getsu 		月 			Month
tsuki 		月          Moon

hi 			火 			Fire
kasei 		火星 		Mars

mizu 		水 			Water
suisei 		水星 		Mercury

ki 			木 			Tree
mokusei		木星 		Jupiter

kin 		金 			Gold
kinsei 		金星 		Venus

tsuchi 		土 			Soil
dosei 		土星 		Saturn
*/
