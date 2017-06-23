all: ./build ./helloworld_en ./helloworld_cn ./main

./build:
	@echo "[Generate Make File]"
	@./tools/gyp/gyp --depth=. -Goutput_dir=./out --generator-output=./build  -f make -Dclang=1

./helloworld_cn:
	@echo "[Build HelloWorld_CN Shared Object]"
	@make helloworld_cn -C ./build V=1

./helloworld_en:
	@echo "[Build HelloWorld_EN Shared Object]"
	@make helloworld_en -C ./build V=1

./main:
	@echo "[Build Main]"
	@make main -C ./build V=1

./test:
	@echo "[Run Test Cases]"
	@./build/out/Debug/main

./clean:
	@echo "[Cleanup Dist]"
	@rm -rf ./build
