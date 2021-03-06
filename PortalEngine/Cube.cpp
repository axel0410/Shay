#include "Cube.h"

Cube::Cube()
{
	pos.x = 0.0;
	pos.y = 0.0;
	pos.z = 0.0;
}

Cube::Cube(const GLfloat x1, const GLfloat y1, const GLfloat z1)
{
	pos.x = x1;
	pos.y = y1;
	pos.z = z1;
}

void Cube::CreateTexture()
{
	j.CreateTexture("pillar", "data/pillarTexture.jpg");
	j.CreateTexture("bottompillar", "data/bottompillar.jpg");
	j.CreateTexture("SWIRL", "data/bark.jpg");
	j.CreateTexture("CLOUD", "data/cloud.jpg");
	j.CreateTexture("ROCK", "data/spacerock.jpg");
	j.CreateTexture("4TH", "data/th.jpg");
	j.CreateTexture("CP", "data/cubePattern.jpg");
	j.CreateTexture("LC", "data/lineCube.jpg");
	j.CreateTexture("AR", "data/alienRock.jpg");
	j.CreateTexture("CB", "data/castleBrick.jpg");
	j.CreateTexture("MAR", "data/marble.jpg");
	j.CreateTexture("GOLD", "data/gold.jpg");
	
}

void Cube::Draw(const GLfloat x1, const GLfloat y1, const GLfloat z1, std::string levelName, const int currentrandomNumber)
{
	
	glPushMatrix();
	glTranslatef(x1,y1,z1);

	if (levelName == "level1" || (levelName == "random" && currentrandomNumber == 0))
	{
		glBindTexture(GL_TEXTURE_2D, j.getTextureID("SWIRL"));
	}
	else
		if (levelName == "level2" || (levelName == "random" && currentrandomNumber == 1))
		{
			glBindTexture(GL_TEXTURE_2D, j.getTextureID("CLOUD"));
		}
		else
			if (levelName == "level3" || (levelName == "random" && currentrandomNumber == 2))
			{
				glBindTexture(GL_TEXTURE_2D, j.getTextureID("ROCK"));
			}
			else
				if (levelName == "level4" || (levelName == "random" && currentrandomNumber == 3))
				{
					glBindTexture(GL_TEXTURE_2D, j.getTextureID("4TH"));
				}
				else
					if (levelName == "level5" || (levelName == "random" && currentrandomNumber == 4))
					{
						glBindTexture(GL_TEXTURE_2D, j.getTextureID("CP"));
					}
					else
						if (levelName == "level6" || (levelName == "random" && currentrandomNumber == 5))
						{
							glBindTexture(GL_TEXTURE_2D, j.getTextureID("LC"));
						}
						else
							if (levelName == "level7" || (levelName == "random" && currentrandomNumber == 6))
							{
								glBindTexture(GL_TEXTURE_2D, j.getTextureID("AR"));
							}
							else
								if (levelName == "level8" || (levelName == "random" && currentrandomNumber == 7))
								{
									glBindTexture(GL_TEXTURE_2D, j.getTextureID("CB"));
								}
								else
									if (levelName == "level9" || (levelName == "random" && currentrandomNumber == 8))
									{
										glBindTexture(GL_TEXTURE_2D, j.getTextureID("MAR"));
									}
									else
										if (levelName == "level10" || (levelName == "random" && currentrandomNumber == 9))
										{
											glBindTexture(GL_TEXTURE_2D, j.getTextureID("GOLD"));
										}


	//front square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2i(0, 1); glVertex3f(2.0, 1.0, 1.0);
		glTexCoord2i(0, 0); glVertex3f(2.0 ,0.0, 1.0);
		glTexCoord2i(1, 0); glVertex3f(1.0, 0.0, 1.0);
	glEnd();

	//left square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2i(0, 1); glVertex3f(1.0,1.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(1.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(1.0,0.0,1.0);
	glEnd();

	//right square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(2.0,1.0,1.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,1.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(2.0,0.0,1.0);
	glEnd();

	//back square
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0,1.0,0.0);
		glTexCoord2i(0, 1); glVertex3f(2.0,1.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(1.0,0.0,0.0);
	glEnd();


	//bottom square
	//glBindTexture(GL_TEXTURE_2D, j.getTextureID("bottompillar"));
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1); glVertex3f(1.0,0.0,1.0);
		glTexCoord2i(0, 1); glVertex3f(1.0,0.0,0.0);
		glTexCoord2i(0, 0); glVertex3f(2.0,0.0,0.0);
		glTexCoord2i(1, 0); glVertex3f(2.0,0.0,1.0);
	glEnd();

	//top square
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 1); glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2i(0, 1); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2i(0, 0); glVertex3f(2.0, 1.0, 0.0);
	glTexCoord2i(1, 0); glVertex3f(2.0, 1.0, 1.0);
	glEnd();


	glPopMatrix();

	
	
}
