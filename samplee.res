###!---------------------------------------------------------------------
###!
###! JOC DE PROVES DE PARTICIO<T>
###!
###! Provarem la particio amb enters (si funciona correctament
###! amb enters, tambe ho fara amb altres tipus).
###!---------------------------------------------------------------------
###!
###!
###!---------------------------------------------------------------------
###1 Particio de 1, 2 i 9 elements
###!---------------------------------------------------------------------
###!
###!---------------------------------------------------------------------
###1.1 Constructor i insercio
###!---------------------------------------------------------------------
###!
###! Constructor particio buida
#init p0 particio<int> 0
###! Intentem inserir element sobrepassant maxim
#p0 afegir 1
Error::particio<T>:41:Particio plena.
##Error::particio<T>:41:Particio plena.
###!
###! Constructor particio amb 1 element
#init p1 particio<int> 1
#p1 afegir 3
###! Intentem inserir element sobrepassant maxim
#p1 afegir 1
Error::particio<T>:41:Particio plena.
##Error::particio<T>:41:Particio plena.
###!
###! Constructor particio amb 2 elements pero espai per 9 elements
#init p2 particio<int> 9
#p2 afegir 3
#p2 afegir 7
###!
###! Constructor particio amb multiples elements
#init p9 particio<int> 9
#p9 afegir 3
#p9 afegir 79
#p9 afegir 5
#p9 afegir 10
#p9 afegir 2
#p9 afegir 9
#p9 afegir 4
#p9 afegir 12
#p9 afegir 15
###! Intentem inserir element repetit
#p9 afegir 5
###! Intentem inserir element sobrepassant maxim
#p9 afegir 1
Error::particio<T>:41:Particio plena.
##Error::particio<T>:41:Particio plena.
###!
###!---------------------------------------------------------------------
###1.2 Consultora numero blocs
###!---------------------------------------------------------------------
###!
#p0 size
0
##0
#p1 size
1
##1
#p2 size
2
##2
#p9 size
9
##9
###!
###!---------------------------------------------------------------------
###1.3 Consultora numero elements i numero maxim
###!---------------------------------------------------------------------
###!
#p0 num_elems
0
##0
#p0 num_maxim
0
##0
###!
###!
#p1 num_elems
1
##1
#p1 num_maxim
1
##1
###!
###!
#p2 num_elems
2
##2
#p2 num_maxim
9
##9
###!
###!
#p9 num_elems
9
##9
#p9 num_maxim
9
##9
###!
###!---------------------------------------------------------------------
###1.4 Unio de blocs
###!---------------------------------------------------------------------
###!
#p0 unir 0 0
1
