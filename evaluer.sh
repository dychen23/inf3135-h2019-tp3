#!/bin/bash

if [ ! -f inf3135-h2019-tp2.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP2/master/inf3135-h2019-tp2.correction
fi

C=0
nbPoints=0
NC='\033[0m'
utilisateur=$(cat cp.txt)

while read line; do
	Color='\033[01;31m'
	resultat="echec" 

	tabP[$C]=${line:0:2};
	tabC[$C]=${line:4:2};
	tabM[$C]=${line:29};
		${line:29};
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
	echo ${tabR[14]}
