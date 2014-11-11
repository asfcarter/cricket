echo "Start build_test cricket script"
echo "Clean cricket"
make clean
echo "Building cricket"
make
echo "Done build!"
echo "FIELDER TEST"
./fielder_test
echo "BOWLER TEST"
./bowler_test 
echo "BATSMAN TEST"
./batsman_test 
echo "PLAYER TEST"
./player_test
echo "INNINGS TEST" 
./innings_test
