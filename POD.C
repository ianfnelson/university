/* UNIT 5 EXERCISE "pod" */

/* Ian F. Nelson,  11-15 April 1996 */

#include <stdio.h>

#define LINES 50	/* Maximum number of patients in list */

int days [] = { 0,31,28,31,30,31,30,31,31,30,31,30,31} ;
/* Number of days in each month */

main () {

    /* Declare structure type: */
    struct data_item {

	char name [ 30 ];  /* Name of patient (up to 30 characters) */
	char diabetic;	   /* 'D' if diabetic, '%' otherwise */
	int day;	   /* Day that patient was last seen */
	int month;	   /* Month that patient was last seen */
	int year;	   /* Year that patient was last seen */
	int lastseen;	   /* Number of days since patient last seen */
	int need_to_see;   /* Should the patients details be displayed */

    }; /* End structure declaration */

    /* Declare necessary arrays and variables: */
    struct data_item patient [ LINES ] ;   /* Patients details array */
    int this_day, this_month, this_year ;  /* Current date */
    int year, month, day ; /* Used in for loops */
    int most_needy ;	   /* Patient most in need of visit */
    int linesout=0 ;	   /* Number of lines which will be outputted */
    int patients ;	   /* The number of patients inputted */
    int duration = 0;	   /* Used when calculating time since last seen */
    int number = 0 ;	   /* Used often when looping through patients */
    int letter = 0 ;	   /* Used often when looping through names */

    /* Obtain current date: */
    scanf ( "%d:%d:%d", &this_day, &this_month, &this_year ) ;

    /* Input patient data: */
    while ( ( number < LINES ) &&
	  ( scanf ( "%c", &patient [ number+1 ].name [ letter ] ) !=EOF ) ) {

	number++ ;

	while ( patient [ number ].name [ letter ] != '%' ) {

	    letter++;
	    scanf ( "%c", &patient [ number ].name [ letter ] ) ;

	}  /* End input of name */

	letter = 0 ;
	scanf ( "%c", &patient [ number ].diabetic) ;

	if (patient [ number ].diabetic == 'D' ) {

	    scanf ( "%c" ) ;

	} /* Move on extra character of input if diabetic */

	scanf ( "%d:%d:%d", &patient [ number ].day,
	    &patient [ number ].month, &patient [ number ].year ) ;

    } /* End input of patient data */

    patients = number ;   /* Set number of patients */
    number = 0;



    /*	The following (rather long!) piece of code calculates the number of
     *	days which have passed between the patient last being seen and the
     *	current date.  Whilst it would probably be safe to assume that no
     *	gap between visits would be greater than a month, I thought it
     *	better to ensure that the code could handle any valid dates.
     */

    while ( number < patients ) {

	duration=0;
	number++;

	/* If there are one or more whole years between the dates, the
	 * following code adds their length(s) (either 365 or 366) to
	 * the duration variable
	 */

	if ( ( this_year - patient [ number ].year ) >1 ) {

	    for ( year = patient [ number ].year + 1 ; year < this_year ;
		year++ ) {

		duration = duration + 365 ;

		if ( ( ( year % 4 == 0 ) && ( year % 100 != 0 ) ) ||
		    ( year % 400 == 0 ) ) {

		    duration++;

		} /* Check for leap years */

	    } /* Loop round, adding whole year lengths */

	} /* End if several years between visits */


	/* If the dates are in different years, the following code adds
	 * the length of any whole months at the end of the earlier year
	 * and start of the later year.  eg If we are considering 17:9:94
	 * to 15:4:96, the code will account for October, November and
	 * December in 1994, and January, February and March in 1996.
	 */

	if ( ( this_year - patient [ number ].year ) >= 1 ) {

	    for ( month = this_month - 1 ; month > 0 ; month-- ) {

		duration = duration + days [ month ] ;

		if ( ( month == 2 ) && ( ( ( this_year % 4 == 0 ) &&
		    ( this_year % 100 != 0 ) ) ||
		    ( this_year % 400 == 0 ) ) ) {
		    duration++;

		} /* Check for leap years */

	    } /* Loop round, adding months at start of current year */

	    for ( month = patient [ number ].month + 1 ; month <= 12 ;
		month++ ) {

		duration = duration + days [ month ] ;

		if ( ( month == 2 ) &&
		    ( ( ( patient [ number ].year % 4 == 0 ) &&
			( patient [ number ].year % 100 != 0 ) ) ||
			( patient [ number ].year % 400 == 0 ) ) ) {

		    duration++ ;

		} /* Check for leap years */

	    } /* Loop round, adding months at end of earlier year */

	} /* End if start and finish in different years */


	/*  The following code sums up the length of any whole months
	 *  between the earlier and later dates if they are both in the
	 *  same year.
	 */

	if ( ( this_year == patient [ number ].year ) &&
	     ( ( this_month - patient [ number ].month ) >1 ) ) {

	    for ( month = this_month - 1 ; month > patient [ number ].month ;
		month-- ) {

		duration = duration + days [ month ] ;

		if ( ( month == 2 ) &&
		    ( ( ( patient [ number ].year % 4 == 0 ) &&
			( patient [ number ].year % 100 != 0 ) ) ||
			( patient [ number ].year % 400 == 0 ) ) ) {

		    duration++;

		} /* Check for leap years */

	    } /* Loop round, adding whole months inbetween dates */

	} /* End if different months but same year */


	/* If the dates are in different months, the following code adds
	 * the final days of the earlier months and the first days of the
	 * later month
	 */

	if ( ( this_month != patient [ number ].month ) ||
	     ( this_year != patient [ number ].year ) ) {

	    duration = duration + this_day ;
	    duration = duration + ( days [ patient [ number ].month ] -
						patient [ number ].day ) ;
	    if ( ( month == 2 ) &&
		( ( ( patient [ number ].year % 4 == 0 ) &&
		    ( patient [ number ].year % 100 != 0 ) ) ||
		    ( patient [ number ].year % 400 == 0 ) ) ) {

		duration++;

	    } /* Check for leap years */

	} /* End adding days if different months */


	/* If the dates are in exactly the same month (ie same year also),
	 * then the following code evaluates the number of days between
	 * the two dates
	 */

	if ( ( this_month == patient [ number ].month ) &&
	    ( this_year == patient [ number ].year ) ) {

	    duration = duration + ( this_day - patient [ number ].day ) ;

	} /* End adding days if exactly same month */

	patient [ number ].lastseen = duration ;
	patient [ number ].need_to_see = 0 ;

	if ( ( duration > 21 ) || ( ( duration >7 ) &&
	   ( patient [ number ].diabetic == 'D' ) ) ) {

	    patient [ number ].need_to_see = 1 ;
	    linesout++ ;

	} /* Decide whether patient needs seeing urgently, and if so,
	   * set the need_to_see marker to 1 and increment the linesout
	   * variable, which indicates the number of patients which need
	   * seeing urgently.
	   */

    } /* End of loop which calculates the number of days since each patient
       * was last seen.
       */


    /* Now that we have all the patients data, and have calculated the
     * length of time since each of them was last seen, we need to decide
     * the order of urgency and display the results.
     */

    while ( linesout != 0 ) {

	most_needy = 0 ;
	patient [ 0 ].diabetic = '%' ;
	patient [ 0 ].lastseen = 1 ;
	/* Set the current most needy patient to be a non-diabetic who was
	 * last seen yesterday, so that any truly needy patient will easily
	 * exceed these criteria
	 */

	number = 0 ;

	while ( number < patients ) {

	    number++ ;

	    if ( ( patient [ number ].need_to_see == 1 ) &&
	       ( ( ( patient [ number ].lastseen >
		     patient [ most_needy ].lastseen ) &&
	       ( patient [ number ].diabetic ==
		 patient [ most_needy ].diabetic ) ) ||
	       ( ( patient [ number ].diabetic == 'D' ) &&
		 ( patient [ most_needy ].diabetic != 'D') ) ) ) {

		most_needy=number;

	    } /* This horrifically complicated if statement decides whether
	       * the patient currently under consideration is more needy
	       * than the patient currently thought to be most needy.
	       * It does this by first checking whether or not the patients
	       * data actually needs to be outputted.  If so, it looks to
	       * see if this patient has been waiting longer than the
	       * "most needy" patient.  If this is also true, and both
	       * patients share the same diabetic status, then the current
	       * patient is deemed more needy.	Likewise if the
	       * current patient is diabetic whereas the "most needy"
	       * patient is not.
	       */

	} /* Loop through all patients */

	linesout--;
	patient [ most_needy ].need_to_see=0 ;


	/* Print out the next most urgent patients data: */
	letter = -1;

	while ( patient [ most_needy ].name [ letter ] != '%') {

	    letter++ ;
	    printf ( "%c", patient [ most_needy ].name [ letter ] ) ;

	} /* End outputting patients name */

	printf ( "%c", patient [ most_needy ].diabetic ) ;

	if ( patient [ most_needy ].diabetic == 'D' ) {

	    printf ( "%%" ) ;

	} /* Print an extra % symbol if patient is diabetic */

	printf ( "%d:%d:%d\n", patient [ most_needy ].day,
			       patient [ most_needy ].month,
			       patient [ most_needy ].year ) ;


    } /* Loop until no more visits are urgent. */

    exit ( 0 ) ;

} /* End main */


