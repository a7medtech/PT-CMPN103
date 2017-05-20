#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Actions/SaveAction.h"

Save::Save(ApplicationManager *pApp):Action(pApp)
{

}
 void Save :: ReadActionParameters()
 {

   Output* pOut = pManager->GetOutput();
   	pOut->PrintMessage("Save to File enter the file name: ");
    filename=pManager->GetInput()->GetSrting(pOut);

   
}
 void Save:: Execute()
 {
     ReadActionParameters();
     Out=new ofstream(filename,ios::out);
     pManager->SaveAction(*Out);


}

 string Save:: tostringg (color c) 
{

 if(c==SNOW) return"SNOW" ;
 if (c==GHOSTWHITE) return"GHOSTWHITE" ;
 if(c==WHITESMOKE) return "WHITESMOKE" ;
 if(c==GAINSBORO) return"GAINSBORO" ;
 if(c==FLORALWHITE) return"FLORALWHITE" ;
 if(c==OLDLACE) return "OLDLACE";
 if(c==LINEN) return "LINEN";
 if(c==ANTIQUEWHITE) return "ANTIQUEWHITE" ;
 if(c==PAPAYAWHIP) return"PAPAYAWHIP" ;
 if(c==BLANCHEDALMOND) return "BLANCHEDALMOND" ;
 if(c==BISQUE) return "BISQUE" ;
 if(c==PEACHPUFF) return"EACHPUFF" ;
if(c==NAVAJOWHITE) return "NAVAJOWHITE" ;
if(c==MOCCASIN) return "MOCCASIN" ;
if(c==CORNSILK) return "CORNSILK" ;
if(c==IVORY) return "IVORY" ;
if(c==LEMONCHIFFON) return "LEMONCHIFFON" ;
if(c==SEASHELL) return "SEASHELL";
if(c==HONEYDEW) return "HONEYDEW" ;
if(c==MINTCREAM) return "MINTCREAM" ;
if(c==AZURE) return "AZURE";
if(c==ALICEBLUE) return"ALICEBLUE" ;
if(c==LAVENDER) return "LAVENDER" ;
if(c==LAVENDERBLUSH) return "LAVENDERBLUSH" ;
if(c==MISTYROSE) return "MISTYROSE" ;
if(c==WHITE) return "WHITE" ;
if(c==BLACK) return "BLACK" ;
if(c==DARKSLATEGRAY) return "DARKSLATEGRAY" ;
if(c==DARKSLATEGREY) return"DARKSLATEGREY" ;
if(c==DIMGRAY) return"DIMGRAY" ;
if(c==DIMGREY) return"DIMGREY" ;
if(c==SLATEGRAY) return "SLATEGRAY";
if(c==SLATEGREY) return"SLATEGREY" ;
if(c==LIGHTSLATEGRAY) return"LIGHTSLATEGRAY" ;
if(c==LIGHTSLATEGREY) return"LIGHTSLATEGREY";
if(c==GRAY) return "GRAY" ;
if(c==GREY) return"GREY" ;
if(c==LIGHTGREY) return "LIGHTGREY" ;
if(c==LIGHTGRAY) return "LIGHTGRAY" ;
if(c==MIDNIGHTBLUE) return"MIDNIGHTBLUE" ;
if(c==NAVY) return"NAVY" ;
if(c==NAVYBLUE) return"NAVYBLUE" ;
if(c==CORNFLOWERBLUE) return"CORNFLOWERBLUE" ;
if(c==DARKSLATEBLUE) return"DARKSLATEBLUE" ;
if(c==SLATEBLUE) return "SLATEBLUE" ;
if(c==MEDIUMSLATEBLUE) return"MEDIUMSLATEBLUE" ;
if(c==LIGHTSLATEBLUE) return"LIGHTSLATEBLUE" ;
 if(c==MEDIUMBLUE) return"MEDIUMBLUE" ;
if(c==ROYALBLUE) return"ROYALBLUE";
if(c==BLUE) return"BLUE" ;
if(c==DODGERBLUE) return"DODGERBLUE";
 if(c==DEEPSKYBLUE) return"DEEPSKYBLUE" ;
 if(c==SKYBLUE) return"SKYBLUE" ;
if(c==LIGHTSKYBLUE) return "LIGHTSKYBLUE";
if(c==STEELBLUE) return"STEELBLUE" ;
 if(c==LIGHTSTEELBLUE) return"LIGHTSTEELBLUE" ;
if(c==LIGHTBLUE) return"LIGHTBLUE" ;
if(c==POWDERBLUE) return"POWDERBLUE" ;
if(c==PALETURQUOISE) return"PALETURQUOISE" ;
if(c==DARKTURQUOISE) return"DARKTURQUOISE" ;
if(c==MEDIUMTURQUOISE) return"MEDIUMTURQUOISE" ;
if(c==TURQUOISE) return"TURQUOISE" ;
if(c==CYAN) return"CYAN" ;
 if(c==LIGHTCYAN) return"LIGHTCYAN" ;
if(c==CADETBLUE) return"CADETBLUE";
if(c==MEDIUMAQUAMARINE) return"MEDIUMAQUAMARINE" ;
if(c==AQUAMARINE) return"AQUAMARINE";
 if(c==DARKGREEN) return"DARKGREEN" ;
if(c==DARKOLIVEGREEN) return"DARKOLIVEGREEN" ;
if(c==DARKSEAGREEN) return"DARKSEAGREEN" ;
if(c==SEAGREEN) return"SEAGREEN" ;
if(c==MEDIUMSEAGREEN) return"MEDIUMSEAGREEN" ;
 if(c==LIGHTSEAGREEN) return"LIGHTSEAGREEN" ;
if(c==PALEGREEN) return"PALEGREEN" ;
if(c==SPRINGGREEN) return"SPRINGGREEN" ;
 if(c==LAWNGREEN) return"LAWNGREEN" ;
 if(c==GREEN) return"GREEN" ;
 if(c==CHARTREUSE) return"CHARTREUSE" ;
 if(c==MEDIUMSPRINGGREEN) return"MEDIUMSPRINGGREEN" ;
 if(c==GREENYELLOW) return"GREENYELLOW";
 if(c==LIMEGREEN) return"LIMEGREEN" ;
 if(c==YELLOWGREEN) return"YELLOWGREEN" ;
if(c==FORESTGREEN) return"FORESTGREEN" ;
if(c==OLIVEDRAB) return"OLIVEDRAB" ;
if(c==DARKKHAKI) return"DARKKHAKI" ;
if(c==KHAKI) return"KHAKI";
if(c==PALEGOLDENROD) return"PALEGOLDENROD" ;
if(c==LIGHTGOLDENRODYELLOW) return"LIGHTGOLDENRODYELLOW" ;
if(c==LIGHTYELLOW) return"LIGHTYELLOW" ;
if(c==YELLOW) return"YELLOW" ;
 if(c==GOLD) return"GOLD" ;
if(c==LIGHTGOLDENROD) return"LIGHTGOLDENROD" ;
 if(c==GOLDENROD) return"GOLDENROD" ;
if(c==DARKGOLDENROD) return"DARKGOLDENROD" ;
if(c==ROSYBROWN) return"ROSYBROWN" ;
 if(c==INDIAN) return"INDIAN" ;
if(c==INDIANRED) return"INDIANRED" ;
 if(c==SADDLEBROWN) return"SADDLEBROWN" ;
 if(c==SIENNA) return"SIENNA" ;
 if(c==PERU) return"PERU" ;
 if(c==BURLYWOOD) return"BURLYWOOD" ;
 if(c==BEIGE) return"BEIGE";
 if(c==WHEAT) return"WHEAT" ;
if(c==SANDYBROWN) return"SANDYBROWN" ;
if(c==TAN) return"TAN" ;
if(c==CHOCOLATE) return"CHOCOLATE" ;
if(c==FIREBRICK) return"FIREBRICK" ;
if(c==BROWN) return"BROWN" ;
if(c==DARKSALMON) return"DARKSALMON" ;
if(c==SALMON) return"SALMON" ;
if(c==LIGHTSALMON) return"LIGHTSALMON" ;
 if(c==ORANGE) return"ORANGE" ;
 if(c==DARKORANGE) return"DARKORANGE" ;
if(c==CORAL) return"CORAL" ;
 if(c==LIGHTCORAL) return"LIGHTCORAL" ;
if(c==TOMATO) return"TOMATO" ;
if(c==ORANGERED) return"ORANGERED" ;
if(c==RED) return"RED" ;
if(c==HOTPINK) return"HOTPINK" ;
if(c==DEEPPINK) return"DEEPPINK" ;
if(c==PINK) return"PINK" ;
 if(c==LIGHTPINK) return"LIGHTPINK" ;
 if(c==PALEVIOLETRED) return"PALEVIOLETRED" ;
 if(c==MAROON) return"MAROON" ;
if(c==MEDIUMVIOLETRED) return"MEDIUMVIOLETRED" ;
if(c==VIOLETRED) return"VIOLETRED" ;
if(c==MAGENTA) return"MAGENTA" ;
if(c==VIOLET) return"VIOLET";
if(c==PLUM) return"PLUM" ;
if(c==ORCHID) return"ORCHID" ;
if(c==MEDIUMORCHID) return"MEDIUMORCHID" ;
if(c==DARKORCHID) return"DARKORCHID" ;
if(c==DARKVIOLET) return"DARKVIOLET" ;
if(c==BLUEVIOLET) return"BLUEVIOLET" ;
if(c==PURPLE) return"PURPLE" ;
if(c==MEDIUMPURPLE) return"MEDIUMPURPLE" ;
if(c==THISTLE) return"THISTLE" ;
if(c==DARKGREY) return"DARKGREY" ;
if(c==DARKGRAY) return"DARKGRAY" ;
if(c==DARKBLUE) return"DARKBLUE" ;
if(c==DARKMAGENTA) return"DARKMAGENTA" ;
if(c==DARKRED) return"DARKRED" ;
if(c==LIGHTGREEN) return"LIGHTGREEN" ;
}

  color Save::tocolor(string c)
  {
 
 if(c=="SNOW") return SNOW ;
 if(c=="GHOSTWHITE") return GHOSTWHITE ;
 if(c=="WHITESMOKE") return WHITESMOKE ;
 if(c=="GAINSBORO") return GAINSBORO ;
 if(c=="FLORALWHITE") return FLORALWHITE ;
if(c=="OLDLACE") return  OLDLACE ;
if(c=="LINEN") return LINEN;
if(c=="ANTIQUEWHITE") return ANTIQUEWHITE ;
 if(c=="PAPAYAWHIP") return PAPAYAWHIP ;
 if(c=="BLANCHEDALMOND") return BLANCHEDALMOND ;
 if(c=="BISQUE") return BISQUE ;
 if(c=="PEACHPUFF") return PEACHPUFF ;
if(c=="NAVAJOWHITE") return  NAVAJOWHITE ;
if(c=="MOCCASIN") return MOCCASIN ;
if(c=="CORNSILK") return CORNSILK ;
if(c=="IVORY") return IVORY ;
if(c=="LEMONCHIFFON") return  LEMONCHIFFON ;
if(c=="SEASHELL") return  SEASHELL;
if(c=="HONEYDEW") return HONEYDEW ;
if(c=="MINTCREAM") return MINTCREAM ;
if(c=="AZURE") return AZURE;
if(c=="ALICEBLUE") return ALICEBLUE ;
if(c=="LAVENDER") return LAVENDER ;
if(c=="LAVENDERBLUSH") return  LAVENDERBLUSH ;
if(c=="MISTYROSE") return MISTYROSE ;
if(c=="WHITE") return WHITE ;
if(c=="BLACK") return BLACK ;
if(c=="DARKSLATEGRAY") return  DARKSLATEGRAY ;
if(c=="DARKSLATEGREY") return  DARKSLATEGREY ;
if(c=="DIMGRAY") return  DIMGRAY ;
if(c=="DIMGREY") return DIMGREY ;
if(c=="SLATEGRAY") return SLATEGRAY;
if(c=="SLATEGREY") return SLATEGREY ;
if(c=="LIGHTSLATEGRAY") return LIGHTSLATEGRAY ;
if(c=="LIGHTSLATEGREY") return  LIGHTSLATEGREY;
if(c=="GRAY") return  GRAY ;
if(c=="GREY") return GREY ;
if(c=="LIGHTGREY") return LIGHTGREY ;
if(c=="LIGHTGRAY") return LIGHTGRAY ;
if(c=="MIDNIGHTBLUE") return MIDNIGHTBLUE ;
if(c=="NAVY") return NAVY ;
if(c=="NAVYBLUE") return NAVYBLUE ;
if(c=="CORNFLOWERBLUE") return CORNFLOWERBLUE ;
if(c=="DARKSLATEBLU") return  DARKSLATEBLUE ;
if(c=="SLATEBLUE") return SLATEBLUE ;
if(c=="MEDIUMSLATEBLUE") return MEDIUMSLATEBLUE ;
if(c=="LIGHTSLATEBLUE") return LIGHTSLATEBLUE ;
 if(c=="MEDIUMBLUE") return MEDIUMBLUE ;
if(c=="ROYALBLUE") return ROYALBLUE;
if(c=="BLUE") return BLUE ;
if(c=="DODGERBLUE") return DODGERBLUE;
 if(c=="DEEPSKYBLUE") return DEEPSKYBLUE ;
 if(c=="SKYBLUE") return SKYBLUE ;
if(c=="LIGHTSKYBLUE") return  LIGHTSKYBLUE;
if(c=="STEELBLUE") return  STEELBLUE ;
 if(c=="LIGHTSTEELBLUE") return LIGHTSTEELBLUE ;
if(c=="LIGHTBLUE") return  LIGHTBLUE ;
if(c=="POWDERBLUE") return POWDERBLUE ;
if(c=="PALETURQUOISE") return PALETURQUOISE ;
if(c=="DARKTURQUOISE") return DARKTURQUOISE ;
if(c=="MEDIUMTURQUOISE") return MEDIUMTURQUOISE ;
if(c=="TURQUOISE") return TURQUOISE ;
if(c=="CYAN") return  CYAN ;
 if(c=="LIGHTCYAN") return LIGHTCYAN ;
if(c=="CADETBLUE") return CADETBLUE ;
if(c=="MEDIUMAQUAMARINE") return MEDIUMAQUAMARINE ;
if(c=="AQUAMARINE") return AQUAMARINE;
 if(c=="DARKGREEN") return DARKGREEN ;
if(c=="DARKOLIVEGREEN") return  DARKOLIVEGREEN ;
if(c=="DARKSEAGREEN") return DARKSEAGREEN ;
if(c=="SEAGREEN") return SEAGREEN ;
if(c=="MEDIUMSEAGREEN") return  MEDIUMSEAGREEN ;
 if(c=="LIGHTSEAGREEN") return LIGHTSEAGREEN ;
if(c=="PALEGREEN") return  PALEGREEN ;
if(c=="SPRINGGREEN") return SPRINGGREEN ;
 if(c=="LAWNGREEN") return LAWNGREEN ;
 if(c=="GREEN") return GREEN ;
 if(c=="CHARTREUSE") return CHARTREUSE ;
 if(c=="MEDIUMSPRINGGREEN") return MEDIUMSPRINGGREEN ;
 if(c=="GREENYELLOW") return GREENYELLOW;
 if(c=="LIMEGREEN") return LIMEGREEN ;
 if(c=="YELLOWGREEN") return YELLOWGREEN ;
if(c=="FORESTGREEN") return FORESTGREEN ;
if(c=="OLIVEDRAB") return OLIVEDRAB ;
if(c=="DARKKHAKI") return DARKKHAKI ;
if(c=="KHAKI") return KHAKI;
if(c=="PALEGOLDENROD") return  PALEGOLDENROD ;
if(c=="LIGHTGOLDENRODYELLOW") return  LIGHTGOLDENRODYELLOW ;
if(c=="LIGHTYELLOW") return LIGHTYELLOW ;
if(c=="YELLOW") return YELLOW ;
 if(c=="GOLD") return LIGHTGOLDENROD ;
 if(c=="GOLDENROD") return GOLDENROD ;
if(c=="DARKGOLDENROD") return DARKGOLDENROD ;
if(c=="ROSYBROWN") return ROSYBROWN ;
 if(c=="INDIAN") return INDIAN ;
if(c=="INDIANRED") return INDIANRED ;
 if(c=="SADDLEBROWN") return SADDLEBROWN ;
 if(c=="SIENNA") return SIENNA ;
 if(c=="PERU") return PERU ;
 if(c=="BURLYWOOD") return BURLYWOOD ;
 if(c=="BEIGE") return BEIGE;
 if(c=="WHEAT") return WHEAT ;
if(c=="SANDYBROWN") return  SANDYBROWN ;
if(c=="TAN") return TAN ;
if(c=="CHOCOLATE") return  CHOCOLATE ;
if(c=="FIREBRICK") return  FIREBRICK ;
if(c=="BROWN") return BROWN ;
if(c=="DARKSALMON") return  DARKSALMON ;
if(c=="SALMON") return SALMON ;
if(c=="LIGHTSALMON") return LIGHTSALMON ;
 if(c=="ORANGE") return ORANGE ;
 if(c=="DARKORANGE") return DARKORANGE ;
if(c=="CORAL") return CORAL ;
 if(c=="LIGHTCORAL") return LIGHTCORAL ;
if(c=="TOMATO") return TOMATO ;
if(c=="ORANGERED") return ORANGERED ;
if(c=="RED") return  RED ;
if(c=="HOTPINK") return HOTPINK ;
if(c=="DEEPPINK") return  DEEPPINK ;
if(c=="PINK") return  PINK ;
 if(c=="LIGHTPINK") return LIGHTPINK ;
 if(c=="PALEVIOLETRED") return PALEVIOLETRED ;
 if(c=="MAROON") return MAROON ;
if(c=="MEDIUMVIOLETRED") return MEDIUMVIOLETRED ;
if(c=="VIOLETRED") return VIOLETRED ;
if(c=="MAGENTA") return MAGENTA ;
if(c=="VIOLET") return VIOLET;
if(c=="PLUM") return PLUM ;
if(c=="ORCHID") return ORCHID ;
if(c=="MEDIUMORCHID") return MEDIUMORCHID ;
if(c=="DARKORCHID") return DARKORCHID ;
if(c=="DARKVIOLET") return DARKVIOLET ;
if(c=="BLUEVIOLET") return BLUEVIOLET ;
if(c=="PURPLE") return PURPLE ;
if(c=="MEDIUMPURPLE") return MEDIUMPURPLE ;
if(c=="THISTLE") return THISTLE ;
if(c=="DARKGREY") return DARKGREY ;
if(c=="DARKGRAY") return DARKGRAY ;
if(c=="DARKBLUE") return DARKBLUE ;
if(c=="DARKCYAN") return DARKCYAN;
if(c=="DARKMAGENTA") return DARKMAGENTA ;
if(c=="DARKRED") return DARKRED ;
if(c=="LIGHTGREEN") return LIGHTGREEN ;
}

 