#!/bin/sh

export TITLE="SFML_App"

printb() {
    tput setaf $2
    tput bold
    echo $1
    tput sgr0
}

printb "#==== Launching installation ====#" 2
cd src
cmake . -DCMAKE_BUILD_TYPE=Release
cmake --build . 
cmake --install .
rm $TITLE
cd ..

printb "#==== Installation finished ====#" 2
