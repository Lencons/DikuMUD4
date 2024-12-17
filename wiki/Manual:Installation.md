<div class="mw-parser-output"><pre> Installing the VME 2.0
 Ken Perry whistler@valhalla.com
 v2.0, 1 April 2001
</pre>
<pre> When installing for the first time or upgrading from a previous ver-
 sion of the VME you should still install first and then upgrade sec-
 ond. Following the install section should get you up in running with
 in minutes.  If you have problems with the installation write
 whistler@valhalla.com.
 
</pre>
<hr />
<p>Table of Contents
</p>
<ol><li>Installing the VME 2.0</li>
<li>Upgrading from a previous VME
<ol><li>Back up old VME first</li>
<li>Moving Player base</li>
<li>Converting Zones</li>
<li>Combining your skils.def with the new commands.def</li>
<li>Converting Socials</li>
<li>Converting Help files</li></ol></li>
<li>Debugging if the Server won't run</li></ol>
<hr />
<pre> 1.  Installing the VME 2.0
</pre>
<pre> Installing the VME 2.0 is quick and painless.  Follow the steps bellow
 and you will be up and running in minutes..
</pre>
<pre> NOTE
</pre>
<pre>      All the following steps assume that you are running the Bash or Ksh
      shells if you use another shell and want to add a list of how to
      please send me your steps and I will add it.
</pre>
<p><br />
</p>
<pre> 1. Download the VME2.0.tgz file and place it in the home directory
    that you will be running the mud as.  We suggest you use a user
    like 'mud'.
</pre>
<pre> 2. As the user that you will be running the mud as untar the VME file.
    Do not untar the file as 'root'.  The following is the command you
    use to untar the file.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      tar zxvf vme-2.0-1.tgz
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 3. Edit the server.cfg in the 'vme2.0/etc/' directory and fill it out.
    The server.cfg has comments that explain what each option does.
</pre>
<pre> 4. Add the profile.txt to your .profile or .bash_profile file
    depending on which one you use when you log on.  You must do this
    even if upgrading from the older VME because the server.cfg
    variable has changed in the profile.
</pre>
<pre> 5. Run the profile again by either logging back on or typing:
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      . .profile
      . .bash_profile
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 6. Change directories into the 'vme2.0/zone' directory and then
    compile all the zones by.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      vmc *.zon
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 7. Change directory into the 'vme2.0/bin/' directory and type
    startvme.
</pre>
<pre> 8. Now telnet into your mud using your domain name and port address
    that you set up in the server.cfg and log on the first immortal
    that you set in the server.cfg.
</pre>
<pre> Congratulations that is all there is to it.
</pre>
<pre> Make sure you read the IMPORTANT file in the doc directory.
</pre>
<p><br />
</p>
<pre> 2.  Upgrading from a previous VME
</pre>
<pre> When upgrading your VME to the new 2.0 version we have tried to make
 the upgrade as painless as possible. It is of corse easier to start
 over again but we all know if you already have a mud running that is
 not always possible.  The following is an explanation of what needs to
 be done to get everything up and running.
</pre>
<pre> IN order to make this as easy as possible we have created a few
 convert scripts that will convert your zones socials and your help
 file to the new format.  We have replaced many of the SFUN_* functions
 with Dil so it is necessary to convert the zones to be able to get
 them to compile The zone convert script has proven to be around 90 to
 95% accurate so if you run into a few errors when compiling don't be
 sup prised but they should be easy enough to fix.
</pre>
<pre> 2.1.  Back up old VME first
</pre>
<pre> We suggest you back up your old VME before you begin moving stuff
 around just incase some how you wipe something out.  First cd into the
 home directory where you VME is located and type the following
 command.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      tar zcvf backupvme.tgz vme1.1
      ______________________________________________________________________
</pre>
<p><br />
</p>
<pre> 2.2.  Moving Player base
</pre>
<pre> To move the player base from your old vme to the new server you can
 use either the cp command or the mv command we suggest however that
 you use cp so that you don't accidentally move your players into never
 never land.  This following command will move the player base only if
 both muds are installed as the same user.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
</pre>
<pre>      //first change directories into lib
      cd vme2.0/lib
</pre>
<pre>      /Next remove the current player directories so they can be replaced
      rm -rf ply
</pre>
<pre>      //Copy the files
      cp - R /home/mud/vme1.1/lib/ply .
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 2.3.  Converting Zones
</pre>
<pre> The zone convert script is written in Gawk and can be edited with a
 regular editor if your nervous and want to know what it is doing.  The
 script only works on one zone file at a time.  To convert one zone do
 the following.
</pre>
<p><br />
</p>
<pre> 1. Copy the script from the 'vme2.0/scripts' directory into the
    directory you will be converting the zones in.
</pre>
<pre> 2. Convert each zone by typing
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      convert.zone filename.zon newfilename.zon
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> NOTE
</pre>
<pre>      If it says no such executable check the permissions and make sure the
      script is executable.
</pre>
<p><br />
</p>
<pre> If you want to convert more than one zone at a time the following is
 what I type at the command line to convert the entire zone directory.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      for u in $(ls *.zon)
      do
      convert.zone $u $u.new
      done
      ______________________________________________________________________
</pre>
<p><br />
</p>
<pre> NOTE
</pre>
<pre>      You must have Gawk installed and the examples are for Bsh and Ksh
      shells only if you are using another shell you may have to change how
      you do this.
</pre>
<p><br />
</p>
<pre> After converting them I then check to make sure the convert went fine
 and then copy the zones back to their original filename with the fol-
 lowing command.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
</pre>
<pre>      for u in $(ls *.zon)
      do
      mv $u.new $u
      done
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 2.4.  Combining your skils.def with the new commands.def
</pre>
<pre> In the new VME there is no skills.def.  The commands.def now allows
 you to alter any commands in the VME and how they are parsed.  The
 commands.def is order sensitive so you must put the commands in the
 order in which you need them to activate for example if you want 'n'
 to parse as north then 'north' needs to be the first command in
 commands.def starting with 'n'.
</pre>
<pre> The commands.def that comes with the vme is totally usable but if you
 have added any skills or commands to the skills.def you will need to
 move them to the new commands.def.
</pre>
<pre> Unfortunately there is no quick script to complete this task.  If you
 write one please submit it so it will be easier for other users of the
 VME.
</pre>
<p><br />
</p>
<pre> 2.5.  Converting Socials
</pre>
<pre> The new socials are nothing but Dil commands so you can make your
 socials do anything you want them to.  We have included have the two
 files you will have to manually add your 'socials.def' into the
 'commands.def'.  Remember you can not have duplicates it may cause the
 VME to crash if you do we are working with removing this problem but I
 am not sure if this has been fixed by the release.  Just make sure you
 don't have duplicates and this will not happen.  To convert your
 socials to the new socials just do the following.
</pre>
<p><br />
</p><p><br />
</p><p><br />
</p><p><br />
</p><p><br />
</p><p><br />
</p>
<pre> ______________________________________________________________________
</pre>
<pre> //make a work directory
 mkdir work
</pre>
<pre> //change into your work directory
 cd work
</pre>
<pre> //copy file from your old vme
 cp /home/mud/vme1.1/etc/actions .
</pre>
<pre> //copy script from new mud
 cp /home/mud/vme2.0/scripts/convert.socials
</pre>
<pre> //convert the socials
 convert.socials actions
 ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> NOTE
</pre>
<pre>      You must have Gawk installed and the examples are for Bsh and Ksh
      shells only if you are using another shell you may have to change how
      you do this.  If it says no such executable check the permissions and
      make sure the script is executable.
</pre>
<p><br />
</p>
<pre> 2.6.  Converting Help files
</pre>
<pre> The new VME's help system is coded entirely in Dil.  This allows you
 to make the help system do what ever you want.  This also means you
 must convert the old files to the new format.  You could leave the
 help files that come with the new VME but that would mean you would be
 missing any of the help files you ahve added.  With this in mind we
 have created two convert scripts one for wizard help and one for
 general help and local help.
</pre>
<pre> We have attempted to make this as easy as possible but it does require
 some work removing and moving files to get it all to convert.  Don't
 stress follow the next steps carefully and you will find the
 conversion process is not as bad as it seems.
</pre>
<p><br />
</p>
<pre> 1. Change directories into the new help file.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      cd /home/mud/vme2.0/etc/help/strings
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 2. Remove all the help files and index files that come with the
    release
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      rm *
      ______________________________________________________________________
</pre>
<p><br />
</p>
<pre> WARNING
</pre>
<pre> When doing 'rm *' make sure your in the right directory everything in
 that directory will be lost and there is no getting it back.
</pre>
<pre> 3. Copy the help files from the old VME to the new one.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      cp /home/mud/vme1.1/etc/help* /home/mud/vme2.0/etc/help/strings
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 4. Copy the convert scripts to the new directory
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      cp /home/mud/vme2.0/scripts/convert.help /home/mud/vme2.0/etc/help/strings
      cp /home/mud/vme2.0/scripts/convert.wizhelp /home/mud/vme2.0/etc/help/strings
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 5. Make both the 'help' and 'help.local' into one file.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      cat help help.local &gt;help.new
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 6. Convert the 'help.new' and 'help.wiz' using the scripts.
</pre>
<p><br />
</p>
<pre>      ______________________________________________________________________
      convert.help help.new
      convert.wizhelp help.wiz
      ______________________________________________________________________
</pre>
<p><br />
</p><p><br />
</p>
<pre> 7. Now just log on and the helps are fixed. No reboot is necessary.
</pre>
<pre> NOTE
</pre>
<pre>      You must have Gawk installed and the examples are for Bsh and Ksh
      shells only if you are using another shell you may have to change how
      you do this.
</pre>
<p><br />
</p><p><br />
</p>
<pre> 3.  Debugging if theServer won't run
</pre>
<pre> If the server doesn't run right up you can look in the log directory
 and edit the following file.
</pre>
<p><br />
</p>
<pre> vme2.0/log/vme.log
</pre>
<p><br />
</p>
<pre> If you don't understand the log don't worry just block the last 50
 lines of your log and send it to:
</pre>
<p><br />
</p>
<pre>      whistler@vlahalla.com
</pre></div>