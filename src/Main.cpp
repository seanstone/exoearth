#include <Pulsar.hpp>
// #include <PulsarMesh.hpp>
#include <PulsarShader.hpp>
// #include <ThreeDShader.hpp>
#include <PulsarScene.hpp>
#include <PulsarWindow.hpp>
using namespace Pulsar;

#include <iostream>
#include <string>
using namespace std;

#include <PulsarCanvas.hpp>
#include "CanvasShader.hpp"

// #include "HEALPix.hpp"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

class MainWindow : public Window
{
public:

	MainWindow();
	~MainWindow();
	void render();

	void update();

protected:
	Renderer renderer;
	// Mesh* mesh;
	// Model* model;
	CanvasShader* shader;
	Canvas* canvas;
	// ThreeDShader* normalShader;
	// Texture* texture;
	// PerspectiveCamera* camera;
	// SceneNode* rootNode;
	// SceneMeshItem* meshItem;
	// SceneModelItem* modelItem;

	void initMeshItem();
	// void initModelItem();
};

MainWindow::MainWindow()
{
	createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Earth");

	renderer.init();
	renderer.setClearColor(vec3(0, 0, 0.5));
	//renderer.setClearColor(vec3(0, 0, 0.1));

	initMeshItem();
	//initModelItem();

	// Projection projection;
	// projection.setProjection(radians(45.0f), WINDOW_WIDTH, WINDOW_HEIGHT, 0.01f, 50.0f);
	//
	// camera = new PerspectiveCamera(vec3(0, 0, 15), vec3(0, 0, -1), vec3(0, 1, 0));
	// camera->setProjection(projection);
	// camera->setAspectRatio((float)WINDOW_WIDTH/(float)WINDOW_HEIGHT);
	// cout << "ratio: " << camera->getAspectRatio() << "\n";
	// camera->setFOV(radians(45.0f), radians(45.0f));
}

// HEALPix<64> healpix(5.f, float3(0,0,0));
//Quad<4> healpix;

// float2* texuv;

void MainWindow::initMeshItem()
{
	bool result = true;
	shader = new CanvasShader;
	result &= shader->addVertexShader(File::readAllText("data/shader/simple.vs"));
	result &= shader->addFragmentShader(File::readAllText("data/shader/simple.fs"));
	result &= shader->compile();
	if(result == false)
	{
		terminate();
		exit(0);
	}

	canvas = new Canvas;
	canvas->setVertices();

	// shader->Shader::bind();
	// shader->setParameter("pointLight.position",vec3(100, -100, 50));
	// shader->setParameter("pointLight.radiant",vec3(1e4));
	// shader->Shader::unbind();

	//healpix.init();

	// texuv = new float2[healpix.NumVertex()];
	// healpix.genTerrain(texuv);
	//healpix.genTextureUV(uv);

	// mesh = new Mesh;
	// mesh->setVertices((vec3*) healpix.Vertices, healpix.NumVertex());
	// mesh->setIndices(healpix.Indices, healpix.NumIndex());
	// mesh->setTextureCoord((vec2*)texuv, healpix.NumVertex());
	// mesh->setNormals((vec3*) healpix.Normals, healpix.NumVertex());

	// Image image;
	// image.load("data/texture/earth.png");
	// //image.load("data/texture/gas_giant_stock_texture_by_enderion.png");
	// //image.load("data/texture/earth-large-with-ocean-mask.png");
	//
	// texture = new Texture;
	// texture->load(&image);
	// texture->enableMipmap(false);
	// //texture->enableMipmap(true);
	// shader->setTexture(texture);

	// rootNode = new SceneNode;
	// meshItem = new SceneMeshItem(mesh);
	// meshItem->setShader(shader);
	// rootNode->addItem(meshItem);
}

// void MainWindow::initModelItem()
// {
// 	bool result = true;
// 	normalShader = new ThreeDShader;
// 	result &= normalShader->addVertexShader(File::readAllText("data/shader/test.vs"));
// 	result &= normalShader->addFragmentShader(File::readAllText("data/shader/BasicLighting.fs"));
// 	result &= normalShader->compile();
// 	if(result == false)
// 	{
// 		terminate();
// 		exit(0);
// 	}
//
// 	normalShader->Shader::bind();
// 	normalShader->setParameter("pointLight.position",vec3(3, 2, 0));
// 	normalShader->setParameter("pointLight.radiant",vec3(3.0f));
// 	normalShader->Shader::unbind();
//
// 	model = new Model;
// 	model->load("data/model/monkey.obj");
//
// 	modelItem = new SceneModelItem(model, normalShader);
// 	rootNode->addItem(modelItem);
// }

MainWindow::~MainWindow()
{
	delete shader;
	// delete mesh;
	// delete texture;
	// delete meshItem;

	//delete normalShader;
	//delete model;
	//delete modelItem;

	// delete camera;
	// delete rootNode;
}

// float rotateVal = 0;
// float rotateValY = 0;

void MainWindow::render()
{
	renderer.clearScreen();
	renderer.initFrame();

	// static float val = 0;
	// static float scal = 1;

	// Transform transform;

	//transform.scale(vec3(1,1,1));
	//transform.translate(vec3(0,0,0));
	//transform.rotate(vec3(cos(val*3.14)*3.14,sin(val*3.14)*3.14,0));
	// transform.rotate(vec3(rotateValY*3.14f, rotateVal*3.14f, 0));
	//
	// rootNode->setTransform(transform);

	// val += 0.004*scal;
	// rootNode->render(camera);
	shader->bind();
	canvas->render();
}

// int clickN;

void MainWindow::update()
{
	// static vec2 lastMousePos = getMousePos();
	//
	// float moveSpeed = 0.025;
	// //Move Camera
	// if(getKeyState(Key::W) == true)
	// 	camera->move(camera->getDirection()*moveSpeed);
	// if(getKeyState(Key::S) == true)
	// 	camera->move(-camera->getDirection()*moveSpeed);
	// if(getKeyState(Key::D) == true)
	// 	camera->move(camera->getRight()*moveSpeed);
	// if(getKeyState(Key::A) == true)
	// 	camera->move(-camera->getRight()*moveSpeed);
	// if(getKeyState(Key::E) == true)
	// 	camera->move(camera->getUp()*moveSpeed);
	// if(getKeyState(Key::C) == true)
	// 	camera->move(-camera->getUp()*moveSpeed);

	//if(getKeyState(Key::Esc) == true)
	// 	exit(0);

	//Mouse movements

	// vec2 mousePos = getMousePos();
	/*if(getMouseState(Button::ButtonLeft))
	{
		vec2 diff = mousePos - lastMousePos;

		Quatf rotateVector = diff.x * camera->getUp() + diff.y * camera->getRight();
		Quatf rotor = exp(0.003 * rotateVector);

		vec3 direction =  rotor * camera->getDirection() * ~rotor;
		camera->setDirection(direction);

		//cout << direction.x << "\t" << direction.y << "\t" << direction.z << endl;
	}*/

	// if(getMouseState(Button::ButtonLeft))
	// {
	/*if(getMouseState(Button::ButtonLeft))
	{
>>>>>>> www
	// 	//cout << mousePos.x << "\t" << mousePos.y << "\n";
	// 	vec2 uv = mousePos / vec2(WINDOW_WIDTH, WINDOW_HEIGHT);
	// 	//cout << uv.x << "\t" << uv.y << "\t";
	//
<<<<<<< HEAD
	// // 	float4 rayVec = (uv.x*2.0f-1.0f)*right*tanf(fov.x*0.5f*camera->getpixelAspectRatio())
	// // 	+ (1.0f-uv.y*2.0f)*up*tanf(fov.y*0.5f)
	// // 	+ direction;
	// // rayVec = normalize(rayVec);
=======
	// 	/*float4 rayVec = (uv.x*2.0f-1.0f)*right*tanf(fov.x*0.5f*camera->getpixelAspectRatio())
	// 	+ (1.0f-uv.y*2.0f)*up*tanf(fov.y*0.5f)
	// 	+ direction;
	// rayVec = normalize(rayVec);*/
	//
	// 	Ray ray = camera-> createCameraRay(uv);
	// 	float3 o = ray.origin, d = normalize(ray.direction);
	// 	float3 w = healpix.Origin - ray.origin;
	// 	//cout << ray.origin << "\t" << ray.direction << "\n";
	// 	float dist = length(w - dot(w, d) * d);
	// 	//cout << dist << "\t";
	// 	//cout << ((dist < healpix.Radius) ? "YES" : "NO");
	// 	float3 intersection = findIntersection(ray, healpix);
	// 	float tht = acos(intersection.z/healpix.Radius), phi = atan2(intersection.y, intersection.x);
	// 	//cout << tht * 180 / M_PI << "\t" << phi * 180 / M_PI;
	// 	//cout << "\n";
	// 	Pixel p = healpix.P(healpix.XY(tht, phi));
	// 	cout << p.f << " " << p.ij << "\n";
	// 	clickN = healpix.Facet[0].NumVertex() * p.f + healpix.Facet[0].N(p.ij);
	//
	// 	texuv[clickN] = float2(0,0);
	//
	// 	mesh->setTextureCoord((vec2*)texuv, healpix.NumVertex());
	//
	// 	//shader->setParameter("clickN", clickN);
	// 	//fflush(stdout);
	//
		//shader->setParameter("clickN", clickN);
		//fflush(stdout);
	// }
	// else if(getMouseState(Button::ButtonRight))
	// {
	// 	//vec2 diff = mousePos - lastMousePos;
	// 	float2 diff = (mousePos/float2(WINDOW_WIDTH,WINDOW_HEIGHT) - float2(0.5)) * 1.f;
	// 	Quatf rotateVector = diff.x * camera->getUp() + diff.y * camera->getRight();
	// 	Quatf rotor = exp(0.03 * rotateVector);
	//
	// 	vec3 pos =  rotor * camera->getPosition() * ~rotor;
	// 	camera->setPosition(pos);
	// 	vec3 dir =  rotor * camera->getDirection() * ~rotor;
	// 	camera->setDirection(dir);
	// 	//Transform transform;
	// 	//transform.rotate(vec3(0, rotateVal, 0));
	// 	//rootNode->setTransform(transform);
	// 	//rootNode->render(camera);
	// }

	// lastMousePos = mousePos;

	//cout << camera->getPosition().y << endl;
}

int main()
{
	MainWindow window;
	window.startLoop();
	window.terminate();

	return 0;
}
