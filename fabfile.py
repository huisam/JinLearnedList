from __future__ import with_statement
import myconfig
from fabric.colors import red,green,blue
from time import sleep

from fabric.api import *
from fabric.contrib.console import confirm
@task
def test():
	"""
	Test manage.py
	"""
	with settings(warn_only=True):
		result = local("./manage.py my_app", capture=True)
	if result.failed and not confirm(red("Tests failed. Continue anyway?",)):
		abort(red("aborting at user request."))

@task(alias='user')
def new_user(username, admin='no', comment="No comment provided"):
    print("New User (%s): %s" % (username, comment))
    pass
@task
def color(arg1):
	"""
	Use green color
	"""
	print(green("This is green."))

def commit():
    local("git add -A && git commit")

def push():
    local("git push")

@task
def hostname():
	name = prompt('Insert the name of command :') 
	run('%s'%name)
@task
def uname():
	with hide('stdout'):
		print(red(run(' uname -a')))

@task
@hosts('localhost','test@192.168.56.102')
def ls():
	with cd('/home/ubuntu/jinmine'):
		run('ls')
		with prefix('./manage.py hi test'):
			run('ls -al')
	run('ls')
	with hide('stderr','stdout'):
		run('ls')
@task
@hosts('test@192.168.56.102')
def deploy():
    code_dir = '/home/test/jinmine'
    with settings(warn_only=True):
        if run("test -d %s" % code_dir).failed:
            run("git clone https://github.com/huisam/jinmine.git")
            sleep(2)
    with cd(code_dir):
        run("git pull")
        run("cat manage.py") 

def exists(path):
    with settings(warn_only=True):
        return run('test -e %s' % path)

def reboots():
	reboot()
@task
@hosts('localhost')
def download():
	with cd('/home/ubuntu/jinmine'):
		put('fabfile.py', '~/')

@task
def runsudo():
	sudo('whoami')

@task
@hosts('localhost','test@192.168.56.102')
def send():
	put('~/.vimrc', '~/test2/')
@task
def unametest():
	run('uname -a')

@task
@hosts('localhost')
def getting():
	get('a.txt', '/home/ubuntu/jinmine')

@task
@hosts('localhost')
def testcd():
	"""
	Use With & Change Directory
	"""
	with cd('/home/ubuntu/jinmine'):
		run('ls')
	run('ls')


