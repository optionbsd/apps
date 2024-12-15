#include <gtk/gtk.h>
#include <stdlib.h>
#include <math.h>

static GtkWidget *entry;

static void on_button_clicked(GtkWidget *button, gpointer data) {
    const gchar *button_label = gtk_button_get_label(GTK_BUTTON(button));
    const gchar *current_text = gtk_entry_get_text(GTK_ENTRY(entry));
    gchar *new_text;

    if (g_strcmp0(button_label, "=") == 0) {
        // Если нажата кнопка "=", выполняем вычисление
        if (g_strcmp0(current_text, "") != 0) {
            GError *error = NULL;

            // Преобразуем строку в математическое выражение и вычисляем результат
            gchar *expression = g_strdup(current_text);

            // Здесь мы пытаемся использовать функцию для парсинга и вычисления
            gdouble result = 0;
            gboolean valid = FALSE;

            // Проверка на математическое выражение
            valid = sscanf(expression, "%lf", &result) == 1;

            if (valid) {
                new_text = g_strdup_printf("%.2f", result); // Печатаем результат
                gtk_entry_set_text(GTK_ENTRY(entry), new_text);
            } else {
                gtk_entry_set_text(GTK_ENTRY(entry), "Ошибка");
            }

            g_free(expression);
        }
    } else if (g_strcmp0(button_label, "C") == 0) {
        // Если нажата кнопка "C", очищаем поле ввода
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    } else {
        // Для всех других кнопок добавляем их текст в поле ввода
        new_text = g_strconcat(current_text, button_label, NULL);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
        g_free(new_text);
    }
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *button_1, *button_2, *button_3, *button_4, *button_5, *button_6, *button_7, *button_8, *button_9, *button_0;
    GtkWidget *button_add, *button_subtract, *button_multiply, *button_divide, *button_equals, *button_clear;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    
    // Поле ввода
    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "0");
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    // Делаем поле ввода расширяемым по горизонтали и вертикали
    gtk_widget_set_halign(entry, GTK_ALIGN_FILL);
    gtk_widget_set_valign(entry, GTK_ALIGN_FILL);
    gtk_widget_set_hexpand(entry, TRUE);
    gtk_widget_set_vexpand(entry, TRUE);
    
    // Кнопки калькулятора
    button_1 = gtk_button_new_with_label("1");
    button_2 = gtk_button_new_with_label("2");
    button_3 = gtk_button_new_with_label("3");
    button_4 = gtk_button_new_with_label("4");
    button_5 = gtk_button_new_with_label("5");
    button_6 = gtk_button_new_with_label("6");
    button_7 = gtk_button_new_with_label("7");
    button_8 = gtk_button_new_with_label("8");
    button_9 = gtk_button_new_with_label("9");
    button_0 = gtk_button_new_with_label("0");
    
    button_add = gtk_button_new_with_label("+");
    button_subtract = gtk_button_new_with_label("-");
    button_multiply = gtk_button_new_with_label("*");
    button_divide = gtk_button_new_with_label("/");
    button_equals = gtk_button_new_with_label("=");
    button_clear = gtk_button_new_with_label("C");
    
    // Настроим расположение кнопок на сетке
    gtk_grid_attach(GTK_GRID(grid), button_1, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_2, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_3, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_add, 3, 1, 1, 1);
    
    gtk_grid_attach(GTK_GRID(grid), button_4, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_5, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_6, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_subtract, 3, 2, 1, 1);
    
    gtk_grid_attach(GTK_GRID(grid), button_7, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_8, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_9, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_multiply, 3, 3, 1, 1);
    
    gtk_grid_attach(GTK_GRID(grid), button_0, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_clear, 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_equals, 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_divide, 3, 4, 1, 1);
    
    // Установим возможность расширяться для кнопок
    gtk_widget_set_halign(button_1, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_2, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_3, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_4, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_5, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_6, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_7, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_8, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_9, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_0, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_add, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_subtract, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_multiply, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_divide, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_equals, GTK_ALIGN_FILL);
    gtk_widget_set_halign(button_clear, GTK_ALIGN_FILL);
    
    gtk_widget_set_vexpand(button_1, TRUE);
    gtk_widget_set_vexpand(button_2, TRUE);
    gtk_widget_set_vexpand(button_3, TRUE);
    gtk_widget_set_vexpand(button_4, TRUE);
    gtk_widget_set_vexpand(button_5, TRUE);
    gtk_widget_set_vexpand(button_6, TRUE);
    gtk_widget_set_vexpand(button_7, TRUE);
    gtk_widget_set_vexpand(button_8, TRUE);
    gtk_widget_set_vexpand(button_9, TRUE);
    gtk_widget_set_vexpand(button_0, TRUE);
    gtk_widget_set_vexpand(button_add, TRUE);
    gtk_widget_set_vexpand(button_subtract, TRUE);
    gtk_widget_set_vexpand(button_multiply, TRUE);
    gtk_widget_set_vexpand(button_divide, TRUE);
    gtk_widget_set_vexpand(button_equals, TRUE);
    gtk_widget_set_vexpand(button_clear, TRUE);
    
    // Подключим обработчики нажатия для кнопок
    g_signal_connect(button_1, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_2, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_3, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_4, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_5, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_6, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_7, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_8, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_9, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_0, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_add, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_subtract, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_multiply, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_divide, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_clear, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(button_equals, "clicked", G_CALLBACK(on_button_clicked), NULL);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
