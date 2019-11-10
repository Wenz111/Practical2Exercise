#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "Practical 2 Exercise"

int question;
float xvalue = 0.0f;
float yvalue = 0.0f;
float xcolor = 243.0f / 255.0f;
float ycolor = 202.0f / 255.0f;
float zcolor = 114.0f / 255.0f;
float autoColorChangeR = 0.0f;
float autoColorChangeG = 0.0f;
float autoColorChangeB = 0.0f;
float xscale = 1.0f;
float yscale = 1.0f;
float zscale = 1.0f;
float angleRotate = 0.0f;
float xRotate = 0.0f;
float yRotate = 0.0f;
float zRotate = 1.0f;
float x2scale = 0.5f;
float y2scale = 0.5f;
float z2scale = 0.5f;

void mainObjectQuestion1() {
	glClearColor(1.0f, 228.0 / 255.0f, 204.0 / 255.0f, 0.9f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(xvalue, yvalue, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(xcolor, ycolor, zcolor);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(-0.5f, -0.5f);
	glEnd();
}

void starObjectQuestion2() {
	glClearColor(1.0f, 228.0 / 255.0f, 204.0 / 255.0f, 0.9f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glScalef(xscale, yscale, zscale);
	glTranslatef(xvalue, yvalue, 0.0f);
	glColor3f(autoColorChangeR, autoColorChangeG, autoColorChangeB);

	// Top Triangle
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.05f * 3, 0.085f * 3);
	glVertex2f(0.0f * 3, 0.258f * 3);
	glVertex2f(0.05f * 3, 0.085f * 3);
	glEnd();

	// Right Top Triangle
	glBegin(GL_TRIANGLES);
	glVertex2f(0.05f * 3, 0.085f * 3);
	glVertex2f(0.23f * 3, 0.085f * 3);
	glVertex2f(0.085f * 3, -0.028f * 3);
	glEnd();

	// Right Bottom Triangle
	glBegin(GL_TRIANGLES);
	glVertex2f(0.085f * 3, -0.028f * 3);
	glVertex2f(0.14f * 3, -0.20f * 3);
	glVertex2f(0.0f * 3, -0.092f * 3);
	glEnd();

	// Left Bottom Triangle
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f * 3, -0.092f * 3);
	glVertex2f(-0.14f * 3, -0.20f * 3);
	glVertex2f(-0.085f * 3, -0.028f * 3);
	glEnd();

	// Left Top Triangle
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.085f * 3, -0.028f * 3);
	glVertex2f(-0.23f * 3, 0.085f * 3);
	glVertex2f(-0.05f * 3, 0.085f * 3);
	glEnd();

	// Center Triangle Polygon
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f * 3, 0.085f * 3);
	glVertex2f(0.05f * 3, 0.085f * 3);
	glVertex2f(0.085f * 3, -0.028f * 3);
	glVertex2f(0.0f * 3, -0.092f * 3);
	glVertex2f(-0.085f * 3, -0.028f * 3);
	glEnd();
}

void squareObjectQuestion3() {
	glClearColor(1.0f, 228.0 / 255.0f, 204.0 / 255.0f, 0.9f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(angleRotate, xRotate, yRotate, zRotate);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.05f, -0.3f);
	glVertex2f(0.05f, -0.3f);
	glVertex2f(0.05f, -0.4f);
	glVertex2f(-0.05f, -0.4f);
	glEnd();
}

void squareObjectQuestion4() {
	glClearColor(1.0f, 228.0 / 255.0f, 204.0 / 255.0f, 0.9f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glScalef(x2scale, y2scale, z2scale);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.1f, 0.1f);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(-0.1f, -0.1f);
	glEnd();
}

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			PostQuitMessage(0);
			break;
		}
		if (wParam == 0x31) {
			// Press key 1 -> display question 1
			question = 1;
			xvalue = 0.0f;
			yvalue = 0.0f;
			xcolor = 243.0f / 255.0f;
			ycolor = 202.0f / 255.0f;
			zcolor = 114.0f / 255.0f;
			break;
		}
		if (wParam == VK_LEFT) {
			// Left key press -> x axis - 0.1f
			xvalue = xvalue - 0.1f;
			break;
		}
		if (wParam == VK_RIGHT) {
			// Right key press -> x axis + 0.1f
			xvalue = xvalue + 0.1f;
			break;
		}
		if (wParam == VK_UP) {
			// Up key press -> y axis + 0.1f
			yvalue = yvalue + 0.1f;
			break;
		}
		if (wParam == VK_DOWN) {
			// Up key press -> y axis - 0.1f
			yvalue = yvalue - 0.1f;
			break;
		}
		if (wParam == 0x52) {
			// R key press -> display pure red
			xcolor = 1.0f;
			ycolor = 0.0f;
			zcolor = 0.0f;
			break;
		}
		if (wParam == 0x47) {
			// G key press -> display pure green
			xcolor = 0.0f;
			ycolor = 1.0f;
			zcolor = 0.0f;
			break;
		}
		if (wParam == 0x42) {
			// B key press -> display pure blue
			xcolor = 0.0f;
			ycolor = 0.0f;
			zcolor = 1.0f;
			break;
		}
		if (wParam == VK_SPACE) {
			// Space key press -> reset object to White and locate at centre
			xcolor = 1.0f;
			ycolor = 1.0f;
			zcolor = 1.0f;
			xvalue = 0.0f;
			yvalue = 0.0f;
			xscale = 1.0f;
			yscale = 1.0f;
			zscale = 1.0f;
			angleRotate = 0.0f;
			xRotate = 0.0f;
			yRotate = 0.0f;
			zRotate = 1.0f;
			x2scale = 0.5f;
			y2scale = 0.5f;
			z2scale = 0.5f;
			break;
		}
		if (wParam == 0x32) {
			// Press key 2 -> To display Question 2
			question = 2;
			xvalue = 0.0f;
			yvalue = 0.0f;
			break;
		}
		if (wParam == 0x4F) {
			// Press key O -> To Up scale Object
			if (xscale < 1.0f) {
				xscale += 0.5f;
				yscale += 0.5f;
				zscale += 0.5f;
			}
			break;
		}
		if (wParam == 0x50) {
			// Press key P -> To Down scale Object
			if (xscale > 0.5f) {
				xscale -= 0.5f;
				yscale -= 0.5f;
				zscale -= 0.5f;
			}
			break;
		}
		if (wParam == 0x33) {
			// Press key 3 -> To display Question 3
			question = 3;
			zRotate = 1.0f;
			break;
		}
		if (wParam == 0x34) {
			// Press key 4 -> To display Question 4
			question = 4;
			squareObjectQuestion4();
			x2scale = 0.5f;
			y2scale = 0.5f;
			z2scale = 0.5f;
			break;
		}
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------

	switch (question)
	{
	case 1:
		mainObjectQuestion1();
		break;
	case 2:
		starObjectQuestion2();

		autoColorChangeR += 0.01f;
		autoColorChangeG += 0.03f;
		autoColorChangeB += 0.05f;

		if (autoColorChangeR > 1.0f) {
			autoColorChangeR = 0.0f;
		}

		if (autoColorChangeG > 1.0f) {
			autoColorChangeG = 0.0f;
		}

		if (autoColorChangeB > 1.0f) {
			autoColorChangeB = 0.0f;
		}
		break;
	case 3:
		squareObjectQuestion3();

		angleRotate += 0.05f;

		if (angleRotate > 360.0f) {
			angleRotate = 0.0f;
		}
		break;
	case 4:
		squareObjectQuestion4();
		x2scale += 0.001f;
		y2scale += 0.001f;
		z2scale += 0.001f;
		break;
	default:
		break;
	}

	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 400,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------