#include <iostream>
#include "model/WG.h"
#include "model/ShoppingItem.h"

int main() {
    WG wg("Meine WG");

    // Personen hinzufügen
    wg.addPerson(Person(1, "Alice"));
    wg.addPerson(Person(2, "Bob"));

    // Einkaufliste
    ShoppingList& sl = wg.getShoppingList();
    FinanceManager& fm = wg.getFinanceManager();

    // ShoppingItem hinzufügen
    sl.addItem(ShoppingItem(10, "Milch", 1));        // ID 10, Name Milch, Menge 1
    sl.addItem(ShoppingItem(11, "Eier", 10));        // ID 11

    // Artikel kaufen
    sl.markBought(10, 2.30, 1);    // Alice kauft Milch für 2,30 €

    // --- Test: Items anzeigen ---
    std::cout << "=== Einkaufsliste ===" << std::endl;
    for (const auto& item : sl.getItems()) {
        std::cout << "ID: " << item.getId()
                  << ", Name: " << item.getName()
                  << ", Gekauft: " << (item.getIsBought() ? "ja" : "nein")
                  << ", Preis: " << item.getPrice()
                  << ", Käufer: "
                  << (item.getBuyer() ? item.getBuyer()->getName() : "—")
                  << std::endl;
    }

    // --- Test: Expenses anzeigen ---
    std::cout << "\n=== Ausgaben ===" << std::endl;
    for (const auto& e : fm.getExpenses()) {
        std::cout << "Grund: " << e.getReason()
                  << ", Betrag: " << e.getAmount()
                  << ", Zahler: " << e.getPayer()->getName()
                  << std::endl;
    }

    // --- Test: Saldo ---
    std::cout << "\n=== Finanzstatus ===" << std::endl;
    std::cout << "Alice bezahlt: " << fm.calculateBalanceForPerson(1) << " €" << std::endl;
    std::cout << "Bob   bezahlt: " << fm.calculateBalanceForPerson(2) << " €" << std::endl;

    return 0;
}
