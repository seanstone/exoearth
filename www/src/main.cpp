#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <html5.h>
#endif

#include <GL/gl.h>

void init()
{
    EM_ASM(
        Module.canvas = document.getElementById('canvas');
        Module.glCtx = Module.canvas.getContext('webgl') || Module.canvas.getContext('experimental-webgl');
        GLctx = Module.glCtx;
    );

    int width, height, isFullscreen;
    emscripten_get_canvas_size(&width, &height, &isFullscreen);
    glViewport(0, 0, width, height);

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int main ()
{
    init();

    return 0;
}