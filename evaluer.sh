#!/bin/bash

if [ ! -f inf3135-h2019-tp2.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP2/master/inf3135-h2019-tp2.correction
fi

C=0
nbPoints=0
NC='\033[0m'
utilisateur=$(cat cp.txt)
sub=`sed "s/'/\'/g" inf3135-h2019-tp2.correction`

while read line; do
	Color='\033[01;31m'
	resultat="echec" 

		
	tabP[$C]=${line:0:2};
	tabC[$C]=${line:4:2};
	tabM[$C]=${line:29};
		${tabM[$C]};
	tabR[$C]=$?;
	
	
	if [ ${tabC[$C]} -eq ${tabR[$C]} ]; then
		resultat="reussi ${tabP[$C]}pts";
		nbPoints=$[$nbPoints+${tabP[$C]}];
		Color='\033[1;32m'
	fi 
	
	echo -e "$C ${tabC[$C]}: ${tabR[$C]} ${Color}$resultat${NC}: ${tabM[$C]}";

	C=$[$C+1];
done < inf3135-h2019-tp2.correction

	echo "";
	echo "Note (total) pour $utilisateur dans inf3135-h2019-tp2: $nbPoints";
	echo "FIN."
	echo ${tabR[14]};	
		
	echo  ;
	ca=`grep -c -e 'default :' -e 'default:' Makefile`
	echo ${ca}
	#echo ${sub}