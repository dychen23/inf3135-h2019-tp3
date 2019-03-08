#!/bin/bash

if [ ! -f inf3135-h2019-tp2.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP2/master/inf3135-h2019-tp2.correction
fi

C=0
nbPoints=0

while read line; do
	utilisateur=$(cat cp.txt) 
	resultat="echec" 

	tabP[$C]=${line:0:2};
	tabC[$C]=${line:4:2};
	tabM[$C]=${line:29};
		${line:29} 2>/dev/null;
	tabR[$C]=$?;

	if [ ${tabC[$C]} -eq ${tabR[$C]} ]; then
		resultat="reussi ${tabP[$C]}pts";
		nbPoints=$[$nbPoints+${tabP[$C]}];
	fi 
	
	echo "$C ${tabC[$C]}: ${tabR[$C]} $resultat : ${tabM[$C]}";

	C=$[$C+1];
done < inf3135-h2019-tp2.correction

	echo "";
	echo "Note (total) pour $utilisateur dans inf3135-h2019-tp2: $nbPoints";
	echo "FIN."
