Tämä on kuin sudo -E valinnalla NOPASSWD eli ajaa ohjelman pääkäyttäjänä kysymättä salasanaa. /etc/joo.conf määrittelee käyttäjät, joilla on siihen oikeus. Tämä jättää huomiotta '-'-alkuiset argumentit alusta, jotta sudo tai doas voidaan linkittää täksi ohjelmaksi.

Jollain tasolla tämä on haaraute rootdo:sta tai rdo:sta, mutta aika paljon kirjoitettu uusiksi.
