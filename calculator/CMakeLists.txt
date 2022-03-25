# CMakeList.txt : projet CMake pour calculator, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("calculator" C)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (calculator "main.c" "main.h" "linkedList.h" "calc.h" "calc.c")

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
