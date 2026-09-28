void estructuraDinamica::ordenarSeleccio() {

    // Indica dónde empieza la parte que todavía no está ordenada
    node *iniciNoOrdenat = inici;

    // Indica el último nodo de la parte ordenada
    node *finalOrdenat = nullptr;

    while (iniciNoOrdenat != nullptr) {

        // Al empezar, suponemos que el primer nodo es el mínimo
        node *minim = iniciNoOrdenat;

        // Guardará el nodo anterior al mínimo
        node *anteriorMinim = nullptr;

        // Punteros para recorrer la parte no ordenada
        node *actual = iniciNoOrdenat;
        node *anterior = nullptr;

        // Buscamos el nodo que contiene el elemento más pequeño
        while (actual->seg != nullptr) {

            anterior = actual;
            actual = actual->seg;

            if (actual->dada < minim->dada) {
                minim = actual;
                anteriorMinim = anterior;
            }
        }

        // Quitamos el nodo mínimo de su posición actual
        if (anteriorMinim != nullptr) {
            anteriorMinim->seg = minim->seg;
        }
        else {
            // El mínimo ya era el primer nodo de la parte no ordenada
            iniciNoOrdenat = minim->seg;
        }

        // El mínimo será el último nodo de la parte ordenada
        minim->seg = nullptr;

        // Si todavía no hay ningún nodo ordenado
        if (finalOrdenat == nullptr) {

            inici = minim;
            finalOrdenat = minim;
        }
        else {

            // Añadimos el mínimo al final de la parte ordenada
            finalOrdenat->seg = minim;
            finalOrdenat = minim;
        }

        // Si el mínimo no era el primer nodo de la parte no ordenada,
        // avanzamos la frontera de la parte no ordenada
        if (iniciNoOrdenat == minim) {
            iniciNoOrdenat = minim->seg;
        }
    }
}


//------------------------------------------------------------------------------------------------------------------
void estructuraDinamica::ordenarSeleccio() {
    node* iniciNoOrdenada = inici;
    node* nouInici = nullptr;
    node* nouFinal = nullptr;

    while (iniciNoOrdenada != nullptr) {
        // --- Buscar el nodo mínimo
        node* anterior = nullptr;
        node* actual   = iniciNoOrdenada;

        node* anteriorMinim = nullptr;   // anterior del mínimo encontrado
        node* minim         = iniciNoOrdenada; // suponer que el primero es el minimo y vamos avanzando

        while (actual != nullptr) {
            if (actual->dada < minim->dada) {
                minim = actual;
                anteriorMinim = anterior;
            }
            anterior = actual;
            actual = actual->seg;
        }

        // --- Sacar el minimo de la lista
        if (anteriorMinim == nullptr) {
            iniciNoOrdenada = minim->seg;
        } else {
            anteriorMinim->seg = minim->seg;
        }

        // --- Añadir el minimo al final de la lista ordenada
        minim->seg = nullptr; // pasa a ser el último de la parte ordenada

        if (nouInici == nullptr) {
            // primera inserción: ordenada estaba vacía
            nouInici = minim;
            nouFinal = minim;
        } else {
            nouFinal->seg = minim;
            nouFinal = minim;
        }
    }

    inici = nouInici;
}
