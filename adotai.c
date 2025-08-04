import pygame
import math
import sys

WIDTH, HEIGHT = 640, 480
CENTER = (WIDTH // 2, HEIGHT // 2)
RADIUS = 120
CIRCLE_RADIUS = 18
STEP_NUM = 32  # 軌道の分割数

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
font = pygame.font.SysFont(None, 30)

step = 0
running = True

def draw_circles(step):
    screen.fill((10, 10, 30))
    pygame.draw.circle(screen, (100, 100, 120), CENTER, RADIUS, 2)
    for i, color in enumerate([(255, 50, 50), (50, 255, 255)]):
        angle = 2 * math.pi * ((step + i * (STEP_NUM // 2)) % STEP_NUM) / STEP_NUM
        x = CENTER[0] + math.cos(angle) * RADIUS
        y = CENTER[1] + math.sin(angle) * RADIUS
        pygame.draw.circle(screen, color, (int(x), int(y)), CIRCLE_RADIUS)
    pygame.draw.circle(screen, (180,180,220), CENTER, 8)
    txt = font.render("SPACE/クリック/タップで進む", True, (255,255,255))
    screen.blit(txt, (20, 20))

while running:
    draw_circles(step)
    pygame.display.flip()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                step = (step + 1) % STEP_NUM
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:  # 左クリック or タッチ
                step = (step + 1) % STEP_NUM
    clock.tick(60)

pygame.quit()
sys.exit()
