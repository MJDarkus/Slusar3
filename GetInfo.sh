#!/usr/bin/bash
echo "Кількість доступних взлів: `pbsnodes -l free | wc -l`" 
echo "Кількість груп з онаковими характеристиками (кількість ядер): `pbsnodes | grep -oE "np = .{2}" |  uniq -d | wc -l`"
echo "Кількість груп з онаковими характеристиками (кількість пам'яті): `pbsnodes | grep -oE "physmem=[0-9]*" |  uniq -d | wc -l`"
                                                                                                                                                                                                             
total_amount=`pbsnodes | grep -oE "physmem=[0-9]*" | grep -oE "[0-9]*" | awk '{s+=$1} END {print s}'`
                                                                                                                                                                                                             
nodes_count=`pbsnodes | grep -oE "np = .{2}" | grep -oE "[0-9]*" | awk '{s+=$1} END {print s}'`
                                                                                                                                                                                                             
avarage_memory=`python3 -c "print($total_amount/$nodes_count/1024/1024 )"`
                                                                                                                                                                                                             
echo "Середня клількість пам'яті на ядро: $avarage_memory Гб."
                                                                                                                                                                                                             
gpus_amount=`pbsnodes | grep -oE "gpus = [0-9]*" | grep -oE "[0-9]*" | awk '{s+=$1} END {print s}'`
                                                                                                                                                                                                             
echo "Кількість відеокарт: $gpus_amount"