#!/bin/sh
: '
NAME : Javier Rios_
CS 4350 – Unix Systems Programming
Section Number : 251
Assignment Number : 2
Due Date : 2 / 12 / 2024 no later than 5:15 pm.
'
echo
echo  "This Script is Designed and Implemented by Javier Rios"
echo 
echo "The function of This script is to:"
echo 
echo "1.  Display the integer arguments that are entered."
echo "2.  Display the smallest of the integer arguments."
echo "3.  Display the largest of the integer arguments."
echo "4.  Sum of the 4 integer arguments."
echo "5.  Product of the 4 integer arguments."
echo "6.  Average of the 4 integer arguments."
echo "7.  Square of each integer argument."
echo "8.  Determine that each integer argument is positive, negative or zero."
echo "9.  Determine that each integer argument is odd, or even."
echo "10. Find all even numbers between 1 and the first integer argument."
echo "11. Find all odd numbers between 1 and the third integer argument."
echo "12. Find the factorial of the last integer argument."
echo "13. Determine whether or not the second integer argument is a prime number."
echo 
echo
read -p "Enter 4 Integer Values ----> " a b c d
 
if [ -z "$d" ]; then
    echo "**** Error - Must input 4 integer Values"
    echo 
    echo 
    echo "End of script"
    echo
    echo "Javier Rios - 2 - 12 - 2024"
    echo
    exit 1
fi

echo
echo "1)  You Entered $a $b $c $d"

min=$a
max=$a

for i in $b $c $d; do
    if [ "$i" -lt "$min" ]; then
        min=$i
    fi
    if [ "$i" -gt "$max" ]; then
        max=$i
    fi
done

echo "2)  The Smallest integer is $min"
echo "3)  The largest integer is $max"

sum=$((a + b + c + d))
echo "4)  $a + $b + $c + $d = $sum"

product=$((a * b * c * d))
echo "5)  $a * $b * $c * $d = $product"

average=$(($sum / 4))
echo "6)  ( $a + $b + $c + $d ) / 4 = $average"

echo "7)  $a * $a = $((a * a)) , $b * $b = $((b * b)) , $c * $c = $((c * c)) , $d * $d = $((d * d))"

echo -n "8)  "
for i in $a $b $c $d; do
    if [ "$i" -gt 0 ]; then
        echo -n "$i is positive, "
    elif [ "$i" -lt 0 ]; then
        echo -n "$i is negative, "
    else
        echo -n "$i is zero, "
    fi
done
echo ""

echo -n "9)  "
for i in $a $b $c $d; do
    if [ $((i % 2)) -eq 0 ]; then
        echo -n "$i is even, "
    else
        echo -n "$i is odd, "
    fi
done
echo ""

echo -n "10) Even numbers between 1 and $a: "
if [ "$a" -lt 1 ]; then
    for ((i=$a+1; i<=1; i++)); do
        if [ $((i % 2)) -eq 0 ]; then
            echo -n "$i "
        fi
    done
else
    for ((i=2; i<=$a; i+=2)); do
        echo -n "$i "
    done
fi
echo ""

echo -n "11  Odd numbers between 1 and $c: "
if [ "$c" -lt 1 ]; then
    for ((i=$c+1; i<=1; i++)); do
        if [ $((i % 2)) -ne 0 ]; then
            echo -n "$i "
        fi
    done
else
    for ((i=1; i<=$c; i+=2)); do
        echo -n "$i "
    done
fi
echo ""

echo -n "12  Factorial of $d: "
if [ "$d" -lt 0 ]; then
    echo "Error: Last integer is negative."
else
    factorial=1
    for ((i=1; i<=$d; i++)); do
        factorial=$((factorial * i))
    done
    echo "$factorial"
fi

echo -n "13) $b is "
if [ "$b" -le 1 ]; then
    echo "not prime (must be greater than 1)."
else
    is_prime=1
    for ((i=2; i*i<=$b; i++)); do
        if [ $((b % i)) -eq 0 ]; then
           is_prime=0
           break
        fi
    done

    if [ $is_prime -eq 1 ]; then
       echo "13) $b is a prime number."
    else
       echo "13) $b is not a prime number."
    fi
fi

echo
echo
echo "End of script"
echo
echo "Javier Rios - 2 - 12 - 2024"

echo
exit 0
