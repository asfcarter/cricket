 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
 
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <GL/gl.h>
#include <GL/glu.h>
 
SDL_Window* displayWindow;
SDL_Renderer* displayRenderer;


void myGluPerspective(double fovy, double aspect, double zNear, double zFar)
{
    double f = 1.0 / tan(fovy * M_PI / 360);  // convert degrees to radians and divide by 2
    double xform[16] =
    {
        f / aspect, 0, 0, 0,
        0,          f, 0, 0,
        0,          0, (zFar + zNear)/(zFar - zNear), -1,
        0,          0, 2*zFar*zNear/(zFar - zNear), 0
    };
    glMultMatrixd(xform);
} 
 
void Display_InitGL()
{
/* Enable smooth shading */
glShadeModel( GL_SMOOTH );
 
/* Set the background black */
glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
 
/* Depth buffer setup */
glClearDepth( 1.0f );
 
/* Enables Depth Testing */
glEnable( GL_DEPTH_TEST );
 
/* The Type Of Depth Test To Do */
glDepthFunc( GL_LEQUAL );
 
/* Really Nice Perspective Calculations */
glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}
/* function to reset our viewport after a window resize */
int Display_SetViewport( int width, int height )
{
/* Height / width ration */
GLfloat ratio;
 
/* Protect against a divide by zero */
if ( height == 0 ) {
height = 1;
}
 
ratio = ( GLfloat )width / ( GLfloat )height;
 
/* Setup our viewport. */
glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );
 
/* change to the projection matrix and set our viewing volume. */
glMatrixMode( GL_PROJECTION );
glLoadIdentity( );
 
/* Set our perspective */
//gluPerspective( 45.0f, ratio, 0.1f, 100.0f );
myGluPerspective( 45.0f, ratio, 0.1f, 100.0f ); 
/* Make sure we're chaning the model view and not the projection */
glMatrixMode( GL_MODELVIEW );
 
/* Reset The View */
glLoadIdentity( );
 
return 1;
}
 
void Display_Render()
{
/* Set the background black */
glClearColor( 1.0f, 0.0f, 1.0f, 0.0f );
/* Clear The Screen And The Depth Buffer */
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
/* Move Left 1.5 Units And Into The Screen 6.0 */
glLoadIdentity();
glTranslatef( -0.5f, 0.2f, -6.8f );
 

 
glBegin( GL_TRIANGLES ); /* Drawing Using Triangles */
glColor3f(1.0, 1.0, 1.0);
glVertex3f( 0.0f, 1.0f, 0.0f ); /* Top */
glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
glVertex3f( 1.0f, -1.0f, 0.0f ); /* Bottom Right */
glEnd( ); /* Finished Drawing The Triangle */

SDL_RenderPresent(displayRenderer);
 
/* Move Right 3 Units */
glTranslatef( 3.0f, 0.0f, 0.0f );
 
glBegin( GL_QUADS ); /* Draw A Quad */
glVertex3f( -1.0f, 1.0f, 0.0f ); /* Top Left */
glVertex3f( 1.0f, 1.0f, 0.0f ); /* Top Right */
glVertex3f( 1.0f, -1.0f, 0.0f ); /* Bottom Right */
glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
glEnd( ); /* Done Drawing The Quad */

SDL_Delay(5000);
SDL_RenderPresent(displayRenderer);

}
 
 
int
main(int argc, char *argv[])
{
TTF_Font *fnt;
TTF_Init();
fnt=TTF_OpenFont("./font/arial.ttf",24);
SDL_Surface *screen;
SDL_Surface *imgTxt;
SDL_Rect txtRect;
SDL_Color fColor;

txtRect.x=10;
txtRect.y=250;
fColor.r=fColor.g=fColor.b=200;
imgTxt=TTF_RenderText_Solid(fnt,"BLah",fColor);


SDL_Init(SDL_INIT_VIDEO);
SDL_RendererInfo displayRendererInfo;
SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &displayWindow, &displayRenderer);
SDL_GetRendererInfo(displayRenderer, &displayRendererInfo);

screen = SDL_CreateRGBSurface(0,300,300,32,0x00FF0000,0x0000FF00,0x000000FF,0xFF000000);

/*TODO: Check that we have OpenGL */
if ((displayRendererInfo.flags & SDL_RENDERER_ACCELERATED) == 0 ||
(displayRendererInfo.flags & SDL_RENDERER_TARGETTEXTURE) == 0) {
/*TODO: Handle this. We have no render surface and not accelerated. */
}
Display_InitGL();
Display_SetViewport(800, 600);
Display_Render();
SDL_BlitSurface(imgTxt,NULL,screen,&txtRect);
SDL_Delay(5000);
SDL_Quit();
return 0;
}
