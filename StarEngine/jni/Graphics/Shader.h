#pragma once

#include "../defines.h"

#ifdef DESKTOP
#include <stdlib.h>
#include <glew.h>
#else
#include <stdlib.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <iostream>
#include <fstream>
//#include "../EventLoop.h"
#include "../Assets/Resource.h"
#endif

namespace star
{
	// Attribute index.
	enum
	{
		ATTRIB_VERTEX,
		ATTRIB_UV,
		NUM_ATTRIBUTES
	};

	class Shader {
	public:
		Shader();
		Shader(const tstring& vsFile, const tstring& fsFile);
		~Shader();

		bool Init(const tstring& vsFile,const tstring& fsFile);

		void Bind();
		void Unbind();

		const GLuint GetId() const;

	private:
		const char* TextFileReading(const tstring& fileName);
		bool CompileShader(GLuint* shader, GLenum type, const tstring& file);

		GLuint mShaderID;
		GLuint mVertexShader;
		GLuint mFragmentShader;

		Shader(const Shader& t);
		Shader(Shader&& t);
		Shader& operator=(const Shader& t);
	};
}
