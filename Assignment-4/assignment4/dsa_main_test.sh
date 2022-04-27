clear
echo "###################################################################################"
echo "##############              GRADING ASSINMENT1 OF DSA               ###############"
echo "##############             (unittest for C++: doctest)              ###############"
echo "###################################################################################"

echo "[1] removing previous output ..."
rm -f ./assignment2

echo "[2] building DSACPP, please wait ..."
g++ ./dsacpp/assignment2.cpp ./dsacpp/src/geom/*.cpp -I ./dsacpp/include -I ./doctest -o assignment2

echo "###################################################################################"
echo "[3] running the test ..."
echo "\n"
./assignment2
echo "\n"
