/* day 2 day */

#include <stdio.h>

int days [] = { 0,31,28,31,30,31,30,31,31,30,31,30,31} ;

main () {

    int stday,stmon,styear;
    int enday,enmon,endyear;
    int day,month,year;
    int durat=0;
    printf ("Days in sep: %d", days[9]);

    printf ("dd:mm:yyyy.....");
    scanf ("%d:%d:%d",&stday,&stmon,&styear);
    printf ("\ndd:mm:yyyy.....");
    scanf ("%d:%d:%d",&enday,&enmon,&endyear);
    printf ("Days in dec: %d",days[12]);

    printf ("\nStartday:  %d",stday);
    printf ("\nEnday:     %d",enday);
    printf ("\n");
    printf ("\nStartmonth:%d",stmon);
    printf ("\nEndmonth:  %d",enmon);
    printf ("\n");
    printf ("\nStartyear: %d",styear);
    printf ("\nEndyear:   %d",endyear);
    printf ("\nDays in dec: %d",days[12]);

/*    days[1]=31;
    printf ("Days in Jan: %d",days[1]);
    days[2]=28;
    days[3]=31;
    days[4]=30;
    days[5]=31;
    days[6]=30;
    days[7]=31;
    days[8]=31;
    days[9]=30;
    printf ("Days in Sep: %d",days[9]);
    days[10]=31;
    days[11]=30;

    days[12]=31;
    printf( "Days in Dec: %d",days[12]);
  */

    if ((endyear-styear) >1 ) {
	printf("\nnyear-styear > 1 ");
	for (year=styear+1; year < endyear; year++) {
	    durat=durat+365;
	    printf ("\nAnother year passed, add 365");
	    if (((year%4 ==0)&&(year%100 != 0))||(year%400 ==0)) {
		durat++;
		printf("\nLeap year, add 1");
	    } /* CHECK FOR LEAP YEARS */
	} /* LOOP ROUND, ADDING YEAR LENGTHS */
    } /* END IF SEVERAL YEARS BETWEEN VISITS */

    if ((endyear-styear) >=1 ) {
	printf("\nendyear-styear >=1");
	for (month=enmon-1; month > 0 ; month--) {
	    durat=durat+days[month];
	    printf ("\nMonth %d so add %d",month,days[month]);
	    if (month==2&&((endyear%4 ==0)&&(endyear%100 != 0))||(endyear%400 ==0)) {
		durat++;
		printf ("\nAdd1 for leapyear");
	    } /* CHECK FOR LEAP YEARS */
	} /* LOOP ROUND, ADDING MONTHS PASSED THIS YEAR */

	for (month=stmon+1; month<=12; month++) {
	    durat=durat+days[month];
	    printf ("\nMonth %d so add %d",month,days[month]);
	    if (month==2&&(((styear%4 ==0)&&(styear%100 != 0))||(styear%400 ==0))) {
		durat++;
		printf ("\nAdd1 for leapyear");
	    } /* CHECK FOR LEAP YEARS */
	} /* LOOP ROUND, ADDING FINAL MONTHS OF STARTING YEAR */
    } /* END IF START AND FINISH IN DIFFERENT YEARS */

    if ((endyear==styear)&&((enmon-stmon)>1)) {
	for (month=enmon-1;month>stmon;month--) {
	    durat=durat+days[month];
	    if (month==2&&(((styear%4==0)&&(styear%100!=0))||(styear%400==0))) {
		durat++;
	    } /* CHECK FOR LEAP YEARS */
	} /* LOOP ROUND, ADDING MONTHS BETWEEN START MONTH AND END MONTH */
    } /* END IF START AND FINISH IN VERY DIFFERENT MONTHS (SAME YEAR!) */

    if ((enmon!=stmon)||(endyear!=styear)) {
	durat=durat+enday;
	durat=durat+(days[stmon]-stday);
	if (stmon==2&&(((styear%4==0)&&(styear%100!=0))||(styear%400==0))) {
	    durat++;
	} /* CHECK FOR LEAP YEARS */
    } /* END ADDING FINAL FEW DAYS DIFFERENCE */

    if ((enmon==stmon)&&(endyear==styear)) {
	durat=durat+(enday-stday);
    } /* END IF EXACTLY SAME MONTH! */

    printf ("\nNumber of days between = %d\n",durat);

} /* end main */



