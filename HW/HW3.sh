#!/bin/bash

#NAME: Javier Rios
#CS 4350 – Unix Systems Programming
#Assignment Number: HW3_
#Due Date: 2 / 21 / 2024 No Later than 5:15 pm

createFile() {
    echo "1. Creating a new File zNew.txt."
    cat << EOF > zNew.txt
Spring 2024
CS4350
Section #
251
Serial # 1
scripts and shell programming
using zeus ide
@ TEXAS STATE UNIVERSITY
Computer Science Department
EOF
echo
}

displayContent() {
    echo "2. The content of the created file is :"
    cat zNew.txt
    echo
}

displayAlphabetChars() {
    echo "3. All lines with alphabet characters :"
    grep -E '[a-zA-Z]' zNew.txt
    echo
}

displayDigits() {
    echo "4. All lines with digits :"
    grep -E '[0-9]' zNew.txt
    echo
}

displayLowercaseChars() {
    echo "5. All lines with lowercase characters :"
    grep '[a-z]' zNew.txt
    echo
}

displayUppercaseChars() {
    echo "6. All lines with uppercase characters :"
    grep '[A-Z]' zNew.txt
    echo
}

displayAlphanumericChars() {
    echo "7. All lines with alphanumeric characters :"
    grep -E '[a-zA-Z0-9]' zNew.txt
    echo
}

displayPunctuationChars() {
    echo "8. All lines with punctuation characters :"
    grep -E '[[:punct:]]' zNew.txt
    echo
}

displayLinesWithS() {
    echo "9. All the lines with the letter S :"
    grep 'S' zNew.txt
    echo
}

displayLinesWithZeus() {
    echo "10. All the lines with the word zeus followed by space :"
    grep -E 'zeus ' zNew.txt
    echo
}

displayProgrammingAtEnd() {
    echo "11. All the line that the word programming appears at the end of the line :"
    grep 'programming$' zNew.txt
    echo
}

displaySpringAtBeginning() {
    echo "12. All the lines that the word Spring appears at the beginning of the sentence :"
    grep '^Spring' zNew.txt
    echo
}

displayCto0() {
    echo "13. All lines that has a word that starts with C and ends with 0 :"
    grep -E '\bC.*0\b' zNew.txt
    echo
}

displayS_to_l() {
    echo "14. All lines that contain a word that starts with s and end with l :"
    grep -E '\bs.*l\b' zNew.txt
    echo
}


deleteFile() {
    echo "15. Deleting the existing File zNew.txt"
    rm zNew.txt
    echo
}

displayContentOrMessage() {
    if [ -f zNew.txt ]; then
        echo "16. Display the content of zNew.txt :"
        cat zNew.txt
        echo
    else
        echo "16. Display the content of zNew.txt : File does not exist."
        echo
    fi
}

echo
echo "Shell Programming By Javier Rios"
echo
createFile
displayContent
displayAlphabetChars
displayDigits
displayLowercaseChars
displayUppercaseChars
displayAlphanumericChars
displayPunctuationChars
displayLinesWithS
displayLinesWithZeus
displayProgrammingAtEnd
displaySpringAtBeginning
displayCto0
displayS_to_l
deleteFile
displayContentOrMessage
echo "Prepared by Javier Rios"
echo "2 – 21 - 2024"
echo
