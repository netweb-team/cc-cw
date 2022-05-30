parser grammar ObjectPascalParser;
options {
	tokenVocab = ObjectPascalLexer;
}



//REGION CLASS
PROTECTED:  PROTECTED_1 | PROTECTED_2;

ClassVisibility: (PUBLIC | PROTECTED | PRIVATE | PUBLISHED)?;

//ENDREGION CLASS