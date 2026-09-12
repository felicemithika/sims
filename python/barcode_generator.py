import barcode
import sys
from barcode.writer import ImageWriter

def generate_barcode(data, filename):
    try:
        writer = ImageWriter()
        writer.set_options({
            'module_width': 0.2,
            'module_height': 15.0,
            'font_size': 10,
            'text_distance': 5.0,
            'quiet_zone': 6.5,
            'background': 'white',
            'foreground': 'black',
            'write_text': True,
        })

        code128 = barcode.get('code128')
        barcode_obj = code128(data, writer=writer)
        saved_filename = barcode_obj.save(filename)
        print(f"SUCCESS: {saved_filename}") 
        return saved_filename
    except Exception as e:
        print(f"ERROR:{str(e)}")
        return None

if __name__=="__main__":
    if len(sys.argv) !=3:
        print("ERROR: Usage: pytho barcode_generator.py <data> <filename>")
        sys.exit(1)
    data  = sys.argv[1]
    filename = sys.argv[2]
    result = generate_barcode(data, filename)

    if result: 
        sys.exit(0)
    else:
        sys.exit(1)
