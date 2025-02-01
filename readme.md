Tämä on kuin sudo -E valinnalla NOPASSWD eli ajaa ohjelman pääkäyttäjänä kysymättä salasanaa. /etc/joo.conf määrittelee käyttäjät, joilla on siihen oikeus. Tämä jättää huomiotta kaikki argumentit alusta, jotta sudo tai doas voidaan linkittää täksi ohjelmaksi. Esim. 'joo -E mount -a' -> 'joo mount -a'.

Ellei sudo ole asennettu ohjelman asennushetkellä, tämä luo automaattisesti linkin /bin/sudo -> /bin/joo.
