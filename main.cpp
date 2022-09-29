#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Mat4.h"

GLuint p_id;
GLint vertex_id = 0;
GLuint matrix_model_id;

float vertices2[] = {
        0, 0, 0,
        0.5, 0, 0,
        0.25, 0, 0.5,
        0.25, 0.5, 0,
};
int indices2[] = {
        0, 2, 1,
        2, 1, 3,
        0, 2, 3,
        0, 1, 3
};
static void getError(GLuint id){
    GLint len;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
    char* message = (char*) malloc(len*sizeof(char));
    glGetShaderInfoLog(id, len, 0, message);
    printf(message);
    free(message);
}
char* readShader(char *nameFile) {
    FILE* filePointer = fopen(nameFile, "rb");
    char* content = NULL;
    long numVal = 0;
    fseek(filePointer, 0L, SEEK_END);
    numVal = ftell(filePointer);
    fseek(filePointer, 0L, SEEK_SET);
    content = (char*) malloc((numVal+1) * sizeof(char));
    fread(content, 1, numVal, filePointer);
    content[numVal] = '\0';
    fclose(filePointer);
    return content;
}
static void CompileShader(GLuint id){
    GLint status;
    glCompileShader(id);
    glGetShaderiv(id, GL_LINK_STATUS, &status);
    if (!status) getError(id);
}
static void LinkProgram(GLuint id){
    GLint status;
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &status);
    if (!status) getError(id);
}
static void CreateShaderProgram (char* vertexShaderFile, char* fragmentShaderFile, GLuint &p_id) {
    char*  vertexShader   = readShader(vertexShaderFile);
    char*  fragmentShader = readShader(fragmentShaderFile);

    /* vertex shader */
    GLuint v_id = glCreateShader(GL_VERTEX_SHADER);
    if (v_id == 0)
        std::cout << "Could not create vertex shader object";

    glShaderSource(v_id, 1, (const char**) &vertexShader, 0);
    CompileShader(v_id);

    /* fragment shader */
    GLuint f_id = glCreateShader(GL_FRAGMENT_SHADER);
    if (f_id == 0)
        std::cout << "Could not create fragment shader object";

    glShaderSource(f_id, 1, (const char**) &fragmentShader, 0);
    CompileShader(f_id);

    /* program */
    p_id = glCreateProgram();
    if (p_id == 0)
        std::cout << "Could not create program object";
    glAttachShader(p_id, v_id);
    glAttachShader(p_id, f_id);
    LinkProgram(p_id);

}

void setup() {
    CreateShaderProgram("../VShader.vs", "../FShader.fs", p_id);
    matrix_model_id = glGetUniformLocation(p_id, "matrix_model");
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glBindAttribLocation(p_id, vertex_id, "aPos");
}

void Redisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(p_id);
    glVertexAttribPointer(vertex_id, 3, GL_FLOAT, GL_FALSE, 0, vertices2);
    glEnableVertexAttribArray(vertex_id);

    Mat4 matrix_model(1); // matriz identidad
    Mat4 matrix_traslacion(0.5, 0.5, 0.3, 1);
    matrix_model = matrix_model.multiplicacion( matrix_traslacion );
    GLboolean transpose = GL_TRUE;
    glUniformMatrix4fv(matrix_model_id, 1, transpose, matrix_model.mat);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, (const void *) indices2);


    Mat4 matrix_model1(1); // matriz identidad
    Mat4 matrix_traslacion1(-0.5, 0.5, -0.3, 1);
    matrix_model = matrix_model1.multiplicacion( matrix_traslacion1 );
    glUniformMatrix4fv(matrix_model_id, 1, transpose, matrix_model.mat);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, (const void *) indices2);

    Mat4 matrix_model2(1); // matriz identidad
    Mat4 matrix_traslacion2(-0.5, -0.5, 0.3, 1);
    matrix_model = matrix_model2.multiplicacion( matrix_traslacion2 );
    glUniformMatrix4fv(matrix_model_id, 1, transpose, matrix_model.mat);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, (const void *) indices2);


    glutSwapBuffers();

}


int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    glutInit(&argc, _argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(400, 300);

    int nWindow = glutCreateWindow("lab7");

    //glutKeyboardFunc( SampleKeyboard );
    glutDisplayFunc( Redisplay );

    //glewExperimental = GL_TRUE;
    glewInit();

    setup();
    glutMainLoop();
    return 0;
}

int main2(){
    Mat4 a(true);
    a.print();
    Mat4 matrix_escala(0.5, 0.3, 0.1, 0);
    Mat4 matrix_traslacion(0.5, 0.3, 0.1, 1);
    matrix_traslacion.print();
    Mat4 mat_model = a.multiplicacion(matrix_traslacion);
    mat_model.print();
    return 0;
}