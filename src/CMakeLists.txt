file( GLOB SOURCES *.cpp) #GLOB : chercher globalement ; SOURCES nom d'une variable ; *.cpp tous les fichiers en .cpp dont on a va stocker une liste dans la variable créée précédement

add_library( Lib STATIC ${SOURCES} ) # Création de la lilbraire (se renseigner sur le STATIC ? )
# Static elle est embarquée dans l'éxécutable
# Dynamique elle est chargé au moment de l'éxécution
# Il crée un fichier lib+leNomDonnéCiDessus.a
