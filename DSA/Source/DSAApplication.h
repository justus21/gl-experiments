#pragma once

#include <Framework/Application.h>
#include <Framework/Camera.h>
#include <Framework/CameraController.h>
#include <Framework/Shader.h>
#include <Framework/Model.h>
#include <Framework/Image.h>
#include <glm/glm.hpp>
#include <GL/glew.h>

class DSAApplication : public fw::Application
{
public:
	explicit DSAApplication();
	virtual ~DSAApplication();
	DSAApplication(const DSAApplication&) = delete;
	DSAApplication(DSAApplication&&) = delete;
	DSAApplication& operator=(const DSAApplication&) = delete;
	DSAApplication& operator=(DSAApplication&&) = delete;

	virtual bool initialize() final;
	virtual void update() final;
	virtual void render() final;
	virtual void gui() final;

private:
	fw::Camera camera;
	fw::CameraController cameraController;
	fw::Shader shader;
	fw::Image image;
	fw::Transformation objTransformation;
	glm::mat4 mvpMatrix;	
	GLuint VAO = 0;
	GLuint vertexBuffer = 0;
	GLuint indexBuffer = 0;
	unsigned int numIndices = 0;

	void createBuffers(const fw::Model& model);
};
