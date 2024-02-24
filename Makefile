cupcake: 
	@echo "Making Cupcakes..."
	@g++ cupcake.cpp -o cupcake
	@echo "run using ./cupcake"

pottery: 
	@echo "Making Cupcakes..."
	@g++ pottery.cpp -o pottery
	@echo "run using ./pottery"

both: 
	@echo "Making Both Executables..."
	@g++ pottery.cpp -o pottery
	@g++ cupcake.cpp -o cupcake
	@echo "run using ./cupcake or ./pottery respectively"

clean: 
	@echo "Cleaning up..."
	@rm cupcake pottery -f
	@echo "Cleaned up!"
