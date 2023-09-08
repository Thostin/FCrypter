from tkinter import Tk, Canvas, Button, PhotoImage, Toplevel, Label
from pathlib import Path

import random


OUTPUT_PATH = Path(__file__).parent
ASSETS_PATH = OUTPUT_PATH / "assets" / "frame1"

def relative_to_assets(path: str) -> Path:
    return ASSETS_PATH / Path(path)

image_image_2 = None
image_2 = None
button_1_image = None
button_2_image = None
button_3_image = None
etiqueta_resultado = None
eleccion_jugador_label = None
eleccion_computadora_label = None



def open_second_window():
    global image_image_2, image_2, button_1_image, button_2_image, button_3_image, etiqueta_resultado, eleccion_jugador_label, eleccion_computadora_label

    second_window = Toplevel(window)
    second_window.geometry("845x543")
    second_window.title("Piedra Papel o Tijera")
    


 
    canvas = Canvas(
        second_window,
        bg="#5B0404",
        height=543,
        width=845,
        bd=0,
        highlightthickness=0,
        relief="ridge"
    )
    canvas.pack(fill="both", expand=True)

    image_image_2 = PhotoImage(
        file=relative_to_assets("imagevs.png"))
    image_2 = canvas.create_image(
        422.0,
        237.0,
        image=image_image_2
    )

    button_1_image = PhotoImage(
        file=relative_to_assets("button_1.png"))
    button_1 = Button(
        canvas,
        image=button_1_image,
        borderwidth=0,
        highlightthickness=0,
        command=lambda: jugar("piedra"),
        relief="flat"
    )
    button_1.place(
        x=107.0,
        y=370.0
    )

    button_2_image = PhotoImage(
        file=relative_to_assets("button_2.png"))
    button_2 = Button(
        canvas,
        image=button_2_image,
        borderwidth=0,
        highlightthickness=0,
        command=lambda: jugar("papel"),
        relief="flat"
    )
    button_2.place(
        x=288.0,
        y=363.0
    )

    button_3_image = PhotoImage(
        file=relative_to_assets("button_3.png"))
    button_3 = Button(
        canvas,
        image=button_3_image,
        borderwidth=0,
        highlightthickness=0,
        command=lambda: jugar("tijera"),
        relief="flat"
    )
    button_3.place(
        x=557.0,
        y=362.0
    )

    etiqueta_resultado = Label(second_window, text="", font=("Press Start 2P", 13), fg="#FFFFFF", bg="#5B0404")
    etiqueta_resultado.place(
        x=290,
        y=60
    )

    eleccion_computadora_label = Label(second_window, text="", font=("Press Start 2P", 14), fg="#FFFFFF", bg="#5B0404")
    eleccion_computadora_label.place(
        x=650,
        y=50
    )

    canvas.create_text(
        13.0,
        8.0,
        anchor="nw",
        text="Jugador",
        fill="#FFFFFF",
        font=("Press Start 2P", 24 * -1)
    )

    canvas.create_text(
        330.0,
        26.0,
        anchor="nw",
        text="Resultado",
        fill="#FFFFFF",
        font=("Press Start 2P", 20 * -1)
    )

    canvas.create_text(
        590.0,
        8.0,
        anchor="nw",
        text="Computadora",
        fill="#FFFFFF",
        font=("Press Start 2P", 23 * -1)
    )

# Computadora
def computadora():
    return random.choice(["piedra", "papel", "tijera"])

# Algorítmo
def jugar(jugador_1):
    eleccion_computadora = computadora()
    resultado = ""

    if jugador_1 in ["piedra", "papel", "tijera"]:
        if jugador_1 == eleccion_computadora:
            resultado = "¡Empate!"
        elif (jugador_1 == "piedra" and eleccion_computadora == "tijera") or \
             (jugador_1 == "papel" and eleccion_computadora == "piedra") or \
             (jugador_1 == "tijera" and eleccion_computadora == "papel"):
            resultado = "¡Jugador 1 gana!"
        else:
            resultado = "¡Computadora gana!"
    else:
        resultado = "Opción inválida. Elige piedra, papel o tijera."

    etiqueta_resultado.config(text=resultado)

    eleccion_computadora_label.config(text=f" {eleccion_computadora.capitalize()}")

window = Tk()

window.geometry("845x543")
window.configure(bg="#5B0404")
window.title("Piedra Papel o Tijera")

canvas = Canvas(
    window,
    bg="#5B0404",
    height=543,
    width=845,
    bd=0,
    highlightthickness=0,
    relief="ridge"
)
canvas.pack(fill="both", expand=True)

image_image_1 = PhotoImage(
    file=relative_to_assets("image_1.png"))
image_1 = canvas.create_image(
    422.0,
    271.0,
    image=image_image_1
)

canvas.create_text(
    33.0,
    61.0,
    anchor="nw",
    text="PIEDRA PAPEL\n\n  O TIJERA",
    fill="#FFFFFF",
    font=("Press Start 2P", 64 * -1)
)

# Botón de inicio
button_image_1 = PhotoImage(
    file=relative_to_assets("button_start.png"))
button_1 = Button(
    canvas,
    image=button_image_1,
    borderwidth=0,
    highlightthickness=0,
    command=open_second_window,
    relief="flat"
)
button_1.place(
    x=271.0,
    y=405.0
)

window.resizable(False, False)
window.mainloop()
