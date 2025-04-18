/* UNIT 5  EXERCISE "cg" */

/* Adapted version for DICE */

/* Ian F. Nelson, 10 April 1995 */

main () {

    #define SPACEFOR 100

    int x_coord [SPACEFOR];
    int y_coord [SPACEFOR];
    int mass [SPACEFOR];
    /* DECLARE NECESSARY ARRAYS */

    int number = 0;
    mass [number] =1;
    int cog_x;
    int cog_y;
    int sumxmass=0;
    int sumymass=0;
    int summass=0;
    /* INITIALIZE OTHER VARIABLES */

    while (number < SPACEFOR && mass[number]!=0) {
	number++;
	scanf ("%d", &x_coord[number]);
	scanf ("%d", &y_coord[number]);
	scanf ("%d", &mass[number]);
    } /* READ DATA IN */

    while (number > 0 ){
	sumxmass=sumxmass+(x_coord[number]*mass[number]);
	sumymass=sumymass+(y_coord[number]*mass[number]);
	summass=summass+mass[number];
	number--;
    } /* CALCULATE SUMMATIONS*/

    cog_x=sumxmass/summass;
    cog_y=sumymass/summass;

    printf ( "x = %d , y = %d", cog_x, cog_y ) ;

}  /* END MAIN */




