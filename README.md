# mBot
Se si usa visual studio 2022 bisogna controllare di aver installato il toolset v142 di VS2019 visto che è quello che usiamo a scuola
'MSVC v142 - VS 2019 C++ Build Tools x64/86'


da questo [commit](https://github.com/TommyT0mmY/mBot/commit/d0b7ceb6ae92ca19dfa0fba319950df0b4bddb61) il compilatore si aspetta che in C: ci sia la libreria di opencv Ver. 4.5.4

è necessario mettere il file opencv_world454d.dll nella stessa cartella dove c'è il file *.vcxproj

teoricamente le proprietà del compilatore dovrebbero essere cosi:

![](https://cdn.discordapp.com/attachments/773571846930956309/914536847957454888/unknown.png)

![](https://cdn.discordapp.com/attachments/773571846930956309/914536888919007272/unknown.png)

e la struttura del progetto

![](https://cdn.discordapp.com/attachments/773571846930956309/914586210503102484/unknown.png)
![](https://cdn.discordapp.com/attachments/773571846930956309/914586210767360071/unknown.png)

è possibile che per questa procedure sia necessario che la cartella include sia nei path
