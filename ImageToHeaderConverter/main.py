import cv2
import numpy as np
import argparse
import os

def image_to_c_array(image_path, output_file, width=200, height=200, bit_depth=8, invert=False, rotate=False):
    # 讀取圖片
    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    
    # 進行左右鏡像
    image = cv2.flip(image, 1)
    
    # 調整圖片大小
    image = cv2.resize(image, (width, height))
    
    # 進行二值化處理
    _, image = cv2.threshold(image, 128, 255, cv2.THRESH_BINARY)
    
    # 黑白轉換
    if invert:
        image = cv2.bitwise_not(image)
    
    # -90度旋轉
    if rotate:
        image = cv2.rotate(image, cv2.ROTATE_90_COUNTERCLOCKWISE)
    
    # 將每一行轉換為指定 bit_depth 的位元，並將其轉換為 byte
    byte_array = []
    for row in image:
        bits = ''.join(['1' if pixel == 255 else '0' for pixel in row])
        for i in range(0, len(bits), bit_depth):
            byte = bits[i:i+bit_depth]
            byte_array.append(int(byte, 2))
    
    # 計算每行字節數
    bytes_per_line = width // bit_depth

    # 從輸出文件名中提取變量名
    var_name = os.path.splitext(os.path.basename(output_file))[0]

    # 轉換為 C 語言的程式碼格式，每行以 bytes_per_line 進行換行
    c_code = f'const unsigned char {var_name}[{len(byte_array)}] PROGMEM = {{\n'
    for i, byte in enumerate(byte_array):
        if i % bytes_per_line == 0:
            c_code += '    '
        c_code += '0X{:02X},'.format(byte)
        if (i + 1) % bytes_per_line == 0:
            c_code += '\n'
    if len(byte_array) % bytes_per_line != 0:
        c_code += '\n'
    c_code += '};'
    
    # 將 C 語言的程式碼輸出到文件
    with open(output_file, 'w') as file:
        file.write(c_code)

    print(f"C code generated and saved to {output_file}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert an image to C array format")
    parser.add_argument('input_image', type=str, help="Path to the input image")
    parser.add_argument('output_file', type=str, help="Path to the output C file")
    parser.add_argument('--width', type=int, default=200, help="Width of the image")
    parser.add_argument('--height', type=int, default=200, help="Height of the image")
    parser.add_argument('--bit_depth', type=int, default=8, help="Bit depth per pixel")
    parser.add_argument('--invert', action='store_true', help="Invert black and white colors")
    parser.add_argument('--rotate', action='store_true', help="-90 degrees rotate")

    args = parser.parse_args()

    image_to_c_array(args.input_image, args.output_file, args.width, args.height, args.bit_depth, args.invert, args.rotate)
