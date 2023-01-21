#include "stdafx.h"
#include "Saisho.h"
#include "Title.h"
#include "Ikusa00.h";


Saisho::~Saisho()
{

}

bool Saisho::Start()
{
	//m_ikusa00 = NewGO<Ikusa00>(0, "ikusa00");

	c_title = NewGO<Title>(0, "title");

	return true;
}

void Saisho::Update()
{
}
