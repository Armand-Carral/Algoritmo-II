#include "array_helpers.h"
#include "weather_utils.h"

/* La librería debe proveer tres funciones: */

/* Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad
de Córdoba según los datos del arreglo.*/
int lower_minimum_temperature (WeatherTable a) {
	int minim_temp = a[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (t_month month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day){
            	int minim_temp2 = a[year][month][day]._min_temp;
            	if(minim_temp2 <= minim_temp)
            		minim_temp = minim_temp2;
            }
        }
    }	
	return minim_temp;
}

/* Un “procedimiento” que registre para cada año entre 1980 y 2016 la mayor temperatura
máxima registrada durante ese año.
NOTA: el procedimiento debe tomar como parametro un arreglo que almacenará los resultados obtenidos.
*/
void max_temp_year (WeatherTable a, int output[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        int maxim_temp = a[year][0][0]._max_temp;
        for (t_month month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
            	int maxim_temp2 = a[year][month][day]._max_temp;
            	if(maxim_temp <= maxim_temp2) {
            		maxim_temp = maxim_temp2;
            	}
            }
        }
        output[year] = maxim_temp;
    }
}

/* Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de
ese año en que se registró la mayor cantidad mensual de precipitaciones
*/
void max_rainfall_month_year (WeatherTable a, t_month output[YEARS]) {
	unsigned int array_prom_rainfall[MONTHS];
	for (unsigned int year = 0u; year < YEARS; ++year) {
        for (t_month month = january; month <= december; ++month) {
            unsigned int prom_rainf = 0;
            unsigned int sum_rainf = 0;
            for (unsigned int day = 0u; day < DAYS; ++day) {
                sum_rainf = sum_rainf + a[year][month][day]._rainfall; 
            }
            prom_rainf = sum_rainf/DAYS;
            array_prom_rainfall[month] = prom_rainf;
        }
        t_month dinamic_month = january;
        unsigned int max = array_prom_rainfall[0];
        for(t_month month = january; month <= december; ++month) {
        	if(max < array_prom_rainfall[month]){
        		max = array_prom_rainfall[month];
        		dinamic_month = month;
        	}
        }
        output[year] = dinamic_month;
    }
}


void string_month_dump (t_month output2 [YEARS]) {
	printf("Months when it was resgistered the maximum rainfall for each year:\n");
    for(unsigned int i = 0u; i < YEARS; ++i){
    	printf("Year %u: ", i + FST_YEAR);
    	unsigned int dinam_month = output2[i] + 1;
    	switch(dinam_month)
    	{
    		case 1:
        	printf("January\n");
        	break;

	        case 2:
	        printf("February\n");
	        break;

	        case 3:
	        printf("March\n");
	        break;

    	    case 4:
	        printf("April\n");
	        break;
	
	        case 5:
	        printf("May\n");
	        break;

	        case 6:
	        printf("June\n");
	        break;

	        case 7:
	        printf("July\n");
	        break;

	        case 8:
	        printf("August\n");
	        break;

	        case 9:
	        printf("September\n");
	        break;

	        case 10:
	        printf("October\n");
	        break;

	        case 11:
	        printf("November\n");
	        break;

	        case 12:
	        printf("December\n");
	        break;

    	    // month doesn't match
	        default:
	        printf("Error! month is not correct");
       }
    }
}

/* ME DEVUELVE EL MES DONDE DE LA MAXIMA PRECIPITACION DE CADA AÑO
    for (unsigned int year = 0u; year < YEARS; ++year) {
    	unsigned int maxim_rainfall = a[0][0][0]._rainfall;
    	t_month maxim_month = january;
        for (t_month month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
            	unsigned int maxim_rainfall2 = a[year][month][day]._rainfall;
            	if(maxim_rainfall <= maxim_rainfall2) {
            		maxim_rainfall = maxim_rainfall2;
            		maxim_month = month;
            	}
            }
            output[year] = maxim_month + 1;
        }
    }
*/
