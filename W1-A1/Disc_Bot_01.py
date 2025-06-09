import os
import random
import discord
from discord.ext import commands
from dotenv import load_dotenv
RULES = {
    'SPOCK': ['SCISSORS', 'ROCK'],
    'SCISSORS': ['PAPER', 'LIZARD'],
    'PAPER': ['ROCK', 'SPOCK'],
    'ROCK': ['SCISSORS', 'LIZARD'],
    'LIZARD': ['SPOCK', 'PAPER']
}

load_dotenv()
TOKEN = os.getenv('DISCORD_TOKEN')
intents = discord.Intents.all()
bot = commands.Bot(command_prefix='Awaken!', intents=intents)
active = False
bot_choice = None 

@bot.command(name='start_game')
async def start_game(ctx):
    global active, bot_choice
    active = True
    choices = ['ROCK', 'PAPER', 'SCISSORS', 'LIZARD', 'SPOCK']
    bot_choice = random.choice(choices)
    await ctx.send(bot_choice)

@bot.event
async def on_message(message):
    global active, bot_choice
    if message.author == bot.user:
        return
    if active:
        user_choice = message.content.upper()
        if user_choice in RULES:
            if user_choice == bot_choice:
                await message.channel.send("It's a tie!")
            elif bot_choice in RULES[user_choice]:
                pass
            else:
                await message.channel.send("I WON")
            active = False
        else:
            await message.channel.send("Invalid choice! Please choose ROCK, PAPER, SCISSORS, LIZARD, or SPOCK.")
    await bot.process_commands(message)
bot.run(TOKEN)