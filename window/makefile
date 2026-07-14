emcc:
	emcc main.c raylib/libraylib.web.a -o index.html -O2 -Iraylib -sUSE_GLFW=3 \
	-sUSE_GLFW=3 -sFULL_ES2=1 -sMAX_WEBGL_VERSION=1

emcc-shell:
	emcc main.c raylib/libraylib.web.a -o index.html -O2 -Iraylib \
	-sUSE_GLFW=3 -sFULL_ES2=1 -sMAX_WEBGL_VERSION=1 --shell-file shell.html

dummy:
