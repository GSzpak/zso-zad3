Zmiany w formacie dyskowym:
W strukturze ext2_inode pamiętana jest lista dwukierunkowa inode'ów
biorących udział w mechanizmie COW (każy inode pamięta swój poprzednik
i następnik). Dostęp do list chroniony jest przez muteks trzymany w
superbloku.

Główne zmiany nastąpiły przy pisaniu do bloku (get_block wywołane z create = 1)
oraz przy usuwaniu bloków (__ext2_truncate_blocks). W obydwu przypadkach
najpierw w ext2_get_branch sprawdzane jest, czy dany blok jest dzielony -
jeśli tak, to:
 - w przypadku pisania - znajdowany jest najniższy dzielony blok w danej gałęzi -
    od jego głębokości alokowana jest nowa gałąź, do której kopiowana jest zawartość
    starej
 - w przypadku truncate - blok nie jest zwalniany.
