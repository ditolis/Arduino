//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        char BufferEnvia[30];
        sprintf(BufferEnvia,"KP%s\r\n",Edit1->Text.c_str());
        DWORD BytesEscritos = 0;
        if(WriteFile(hCom, BufferEnvia, strlen(BufferEnvia), &BytesEscritos,NULL) == 0)
        {
                Application->MessageBox("Erro ao Enviar SetPoint","Erro", MB_OK);
        }
        sprintf(BufferEnvia,"KI%s\r\n",Edit2->Text.c_str());
        if(WriteFile(hCom, BufferEnvia, strlen(BufferEnvia), &BytesEscritos,NULL) == 0)
        {
                Application->MessageBox("Erro ao Enviar SetPoint","Erro", MB_OK);
        }
        sprintf(BufferEnvia,"KD%s\r\n",Edit3->Text.c_str());
        if(WriteFile(hCom, BufferEnvia, strlen(BufferEnvia), &BytesEscritos,NULL) == 0)
        {
                Application->MessageBox("Erro ao Enviar SetPoint","Erro", MB_OK);
        }
}
//---------------------------------------------------------------------------

